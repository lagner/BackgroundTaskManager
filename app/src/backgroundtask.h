#ifndef BACKGROUNDTASK_H
#define BACKGROUNDTASK_H

#include <QObject>
#include "common.h"

class WordCounter;

class BackgroundTask : public QObject
{
    Q_OBJECT

public:
    BackgroundTask(const QString& path);
    ~BackgroundTask();

signals:
    void finished();

    void progressChanged(int percent);

    void processedLinesChanged(int lines);

    void uniqueWordsChanged(int words);

    void dataReady(MentionsHashShared mentions);

public slots:
    void run();

private:
    bool processStream(std::ifstream& stream, WordCounter& counter);

private:
    const QString m_filepath;
};

#endif // BACKGROUNDTASK_H
