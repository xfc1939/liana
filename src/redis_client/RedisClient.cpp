#include "RedisClient.h"

#include <QDebug>
#include <QObject>

namespace liana {

RedisClient::RedisClient(const QString &address) {
    const auto &ip_and_port = address.split(":");

    if (2 != ip_and_port.size()) {
        return ;
    } else {
        ip_address_ = ip_and_port[0];

        bool ok = false;
        port_ = static_cast<qint16>(ip_and_port[1].toShort(&ok));
        if (!ok) {
            return ;
        }

        is_connected = connect();
    }
}

bool RedisClient::connect() {
    socket_.connectToHost(ip_address_, port_, QTcpSocket::ReadWrite);
    auto connected = socket_.waitForConnected(3000);

    if (connected) {
        connect(&socket_, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    }

    return false;
}

void RedisClient::onReadyRead() {
    qDebug() << "onreadyread." << endl;
}

} // namespace liana
