#ifndef COMMON_H
#define COMMON_H

#include <QHash>
#include <QSharedPointer>


typedef QHash<const QString, size_t>    MentionsHash;
typedef QSharedPointer<MentionsHash>    MentionsHashShared;


#endif // COMMON_H

