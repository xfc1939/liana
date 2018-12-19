#ifndef REDISCLIENT_H
#define REDISCLIENT_H

#include <QString>
#include <QObject>
#include <QTcpSocket>

namespace liana {

class RedisClient : public QObject {
    Q_OBJECT
public:
    explicit RedisClient(const QString &address);

    bool isConnected() const {return is_connected;}

public slots:
    void onReadyRead();

private:
    bool connectToRedisServer();

private:
    QString ip_address_;
    quint16 port_;
    bool is_connected = false;

    QTcpSocket socket_;
};

} // namespace liana

#endif
