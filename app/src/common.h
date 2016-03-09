#ifndef TYPES
#define TYPES

#include <QHash>
#include <QSharedPointer>


typedef QHash<const QString, size_t>    MentionsHash;
typedef QSharedPointer<MentionsHash>    MentionsHashShared;


#endif // TYPES

