#ifndef WORDMENTIONSMODEL_H
#define WORDMENTIONSMODEL_H

#include <QAbstractListModel>
#include "common.h"


class WordMentionsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum class Roles {
        WORD = Qt::UserRole + 1,
        AMOUNT
    };

public:
    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

public slots:
    void resetData(MentionsHashShared mentions);

    void clearData();

private:
    MentionsHash m_words;
};

#endif // WORDMENTIONSMODEL_H
