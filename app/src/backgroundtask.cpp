#include "backgroundtask.h"
#include <fstream>
#include <QDebug>
#include <QThread>
#include <QCoreApplication>
#include <QElapsedTimer>
#include "wordcounter.h"
#include "utils.h"

namespace {

const size_t TIMEOUT_MSEC = 200;

std::streampos getRemainingSize(std::ifstream& stream) {
    if (!stream)
        return 0;

    auto last = stream.tellg();
    stream.seekg(0, stream.end);
    auto size = stream.tellg();
    stream.seekg(last, stream.beg);

    return size;
}

} /* namespace */


BackgroundTask::BackgroundTask(const QString& filepath)
    : m_filepath(filepath)
{
}

BackgroundTask::~BackgroundTask()
{
}

void BackgroundTask::run()
{
    FinallyGuard guard([this]() {
        emit finished();
    });

    const std::string path = m_filepath.toStdString();

    std::ifstream file(path.c_str(), std::ifstream::in);
    if (!file) {
        qDebug() << "can not open file: " << m_filepath;
        return;
    }

    WordCounter counter;

    if (processStream(file, counter)) {
        auto& res = counter.result();
        auto shared = MentionsHashShared::create(std::move(res));

        emit dataReady(shared);
    }
}

bool BackgroundTask::processStream(std::ifstream &stream, WordCounter& counter)
{
    int lines = 0;
    int linesTotal = 0;
    int uniqueWords = counter.uniqueWords();
    double remain = getRemainingSize(stream);

    std::string line;

    QElapsedTimer timer;
    timer.start();

    auto notifyChanged = [&]() {
        if (linesTotal != lines) {
            linesTotal = lines;
            emit processedLinesChanged(linesTotal);
        }

        int words = counter.uniqueWords();
        if (uniqueWords != words) {
            uniqueWords = words;
            emit uniqueWordsChanged(uniqueWords);
        }

        double pos = stream.tellg();
        if (pos == -1) {
            if (!stream.eof())
                return;
            pos = remain;
        }
        emit progressChanged(pos / remain * 100);
    };

    while (std::getline(stream, line)) {
        const QString data = QString::fromUtf8(line.c_str());
        counter.process(data);

        ++lines;

        if (QThread::currentThread()->isInterruptionRequested())
            return false;

        // prevent event flood
        if (timer.hasExpired(TIMEOUT_MSEC)) {
            notifyChanged();
            timer.restart();
        }
    }

    notifyChanged();
    return true;
}
