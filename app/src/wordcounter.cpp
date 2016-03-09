#include "wordcounter.h"
#include <QDebug>
#include <QStringRef>


WordCounter::WordCounter()
{
}

void WordCounter::process(const QString &text)
{
    using std::string;

    size_t pos = string::npos;

    for (int i = 0, ie = text.length(); i < ie; ++i) {
        auto ch = text[i];

        if (pos == string::npos) {
            if (ch.isLetterOrNumber())
                pos = i;

        } else if (!ch.isLetterOrNumber()) {
            Q_ASSERT(pos != string::npos);
            Q_ASSERT((i - pos) > 0);

            const QString word = text.mid(pos, i - pos);

            insertOrIncrement(word);

            pos = string::npos;
        }
    }

    if (pos != string::npos) {
        const QString word = text.mid(pos, text.length() - pos);
        insertOrIncrement(word);
    }
}


void WordCounter::insertOrIncrement(const QString &word)
{
    const auto it = m_counter.find(word);

    if (it != m_counter.end()) {
        auto& value = it.value();
        ++value;

    } else {
        m_counter.insert(word, 1);
    }
}


const MentionsHash& WordCounter::result() const
{
    return m_counter;
}

MentionsHash& WordCounter::result()
{
    return m_counter;
}

size_t WordCounter::uniqueWords() const
{
    return m_counter.size();
}

size_t WordCounter::repetitions(const QString &word) const
{
    const auto it = m_counter.find(word);

    if (it == m_counter.end())
        return 0;

    return it.value();
}
