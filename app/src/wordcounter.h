#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <QHash>
#include "common.h"


class WordCounter
{
public:
    WordCounter();

    void process(const QString& text);

    MentionsHash& result();

    const MentionsHash& result() const;

    size_t uniqueWords() const;

    size_t repetitions(const QString& word) const;

private:
    void insertOrIncrement(const QString& word);

private:
    MentionsHash m_counter;
};

#endif // WORDCOUNTER_H
