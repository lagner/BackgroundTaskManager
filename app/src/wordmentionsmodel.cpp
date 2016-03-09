#include "wordmentionsmodel.h"
#include <QDebug>


QHash<int, QByteArray> WordMentionsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert((int)Roles::WORD, "word");
    roles.insert((int)Roles::AMOUNT, "amount");
    return roles;
}

int WordMentionsModel::rowCount(const QModelIndex&) const
{
    return m_words.size();
}

QVariant WordMentionsModel::data(const QModelIndex& index, int role) const
{
    if (index.row() >= (int)m_words.size())
        return QVariant();

    switch (role) {
    case (int)Roles::WORD: {
        auto it = m_words.begin() + index.row();
        return it.key();
    }
    case (int)Roles::AMOUNT: {
        auto it = m_words.begin() + index.row();
        return (qulonglong)it.value();
    }
    default:
        qDebug() << "Unknown WordMentionsModel role: " << role;
    }

    return QVariant();
}

void WordMentionsModel::resetData(MentionsHashShared mentions)
{
    if (!mentions)
        return;

    beginResetModel();
    m_words.swap(*mentions);
    endResetModel();
}

void WordMentionsModel::clearData()
{
    beginResetModel();
    m_words.clear();
    endResetModel();
}
