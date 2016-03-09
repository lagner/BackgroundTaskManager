#include <QString>
#include <QtTest>
#include "wordcounter.h"

class WordCounterTests : public QObject
{
    Q_OBJECT

public:
    WordCounterTests();

private Q_SLOTS:
    void emptyLine();
    void repeated();
    void unique();
    void marks();
    void spaces();
};

WordCounterTests::WordCounterTests()
{
}

void WordCounterTests::emptyLine()
{
    WordCounter counter;
    counter.process("");

    QCOMPARE(counter.uniqueWords(), size_t(0));
}

void WordCounterTests::repeated()
{
    WordCounter counter;
    counter.process("aa aa ttel ada aa");
    QCOMPARE(counter.uniqueWords(), size_t(3));
    QCOMPARE(counter.repetitions("aa"), size_t(3));
}

void WordCounterTests::unique()
{
    WordCounter counter;
    counter.process("a b adfasdfasdfa r4   ");
    QCOMPARE(counter.uniqueWords(), size_t(4));
}

void WordCounterTests::marks()
{
    WordCounter counter;
    counter.process("aa, ds!$$ #! # word");
    QCOMPARE(counter.uniqueWords(), size_t(3));
}

void WordCounterTests::spaces()
{
    WordCounter counter;
    counter.process("    aaa teher, , adf  &aaa   ");
    QCOMPARE(counter.uniqueWords(), size_t(3));
    QCOMPARE(counter.repetitions("aaa"), size_t(2));
}


QTEST_APPLESS_MAIN(WordCounterTests)

#include "tst_wordcountertests.moc"
