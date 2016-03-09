#include "context.h"
#include <QDebug>
#include <QThread>
#include <QUrl>
#include "backgroundtask.h"


Context::Context()
{
}

Context::~Context()
{
    if (m_task)
        emit cancelProcessing();
}

void Context::reset()
{
    m_progress = 0;
    m_processedLines = 0;
    m_uniqueWords = 0;
    m_mentions.clearData();
}

void Context::setProgress(int progress)
{
    if (m_progress != progress) {
        m_progress = progress;
        emit progressChanged();
    }
}

void Context::setProcessedLines(int lines)
{
    if (m_processedLines != lines) {
        m_processedLines = lines;
        emit processedLinesChanged();
    }
}

void Context::setUniqueWords(int words)
{
    if (m_uniqueWords != words) {
        m_uniqueWords = words;
        emit uniqueWordsChanged();
    }
}

void Context::onTaskFinished()
{
    m_task = nullptr;
}

void Context::runFileProcessing(const QUrl& filepath)
{
    if (m_task) {
        disconnect(m_task, 0, this, 0);
        disconnect(m_task, 0, &m_mentions, 0);
        emit cancelProcessing();
    }

    reset();

    QThread* m_thread = new QThread();
    m_task = new BackgroundTask(filepath.toLocalFile());
    m_task->moveToThread(m_thread);

    // start/stop
    connect(m_thread, &QThread::started,
            m_task, &BackgroundTask::run);

    connect(this, &Context::cancelProcessing,
            m_thread, &QThread::requestInterruption);

    // change data
    connect(m_task, &BackgroundTask::progressChanged,
            this, &Context::setProgress);

    connect(m_task, &BackgroundTask::processedLinesChanged,
            this, &Context::setProcessedLines);

    connect(m_task, &BackgroundTask::uniqueWordsChanged,
            this, &Context::setUniqueWords);

    connect(m_task, &BackgroundTask::dataReady,
            &m_mentions, &WordMentionsModel::resetData);

    // finish, release resources
    connect(m_task, &BackgroundTask::finished,
            this, &Context::onTaskFinished);

    connect(m_task, &BackgroundTask::finished,
            m_thread, &QThread::quit);

    connect(m_thread, &QThread::finished,
            m_task, &BackgroundTask::deleteLater);

    connect(m_thread, &QThread::finished,
            m_thread, &QThread::deleteLater);

    m_thread->start();
}
