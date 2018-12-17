#ifndef REDISCLIENT_H
#define REDISCLIENT_H

#include <QObject>
#include <QTcpSocket>

namespace liana {

class RedisClient : public QObject {
    Q_OBJECT
public:

private:
    QTcpSocket socket;
};

} // namespace liana

#endif
