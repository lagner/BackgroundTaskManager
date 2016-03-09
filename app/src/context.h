#ifndef CONTEXT_H
#define CONTEXT_H

#include <QObject>
#include "wordmentionsmodel.h"

class BackgroundTask;

class Context : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(int processedLines READ processedLines NOTIFY processedLinesChanged)
    Q_PROPERTY(int uniqueWords READ uniqueWords NOTIFY uniqueWordsChanged)
    Q_PROPERTY(QAbstractItemModel* mentions READ mentions CONSTANT)

public:
    Context();
    ~Context();

    int progress() const 		{ return m_progress; }
    int processedLines() const 	{ return m_processedLines;}
    int uniqueWords() const 	{ return m_uniqueWords; }

    WordMentionsModel* mentions() { return &m_mentions; }

    Q_INVOKABLE void runFileProcessing(const QUrl& filepath);

signals:
    void cancelProcessing();
    void progressChanged();
    void processedLinesChanged();
    void uniqueWordsChanged();

private slots:
    void setProgress(int progress);
    void setProcessedLines(int lines);
    void setUniqueWords(int words);

    void onTaskFinished();
    void reset();

private:
    int m_progress 			= 0;
    int m_processedLines 	= 0;
    int m_uniqueWords 		= 0;

    WordMentionsModel m_mentions;

    BackgroundTask* m_task = nullptr;
};

#endif // CONTEXT_H
