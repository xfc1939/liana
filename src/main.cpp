#include "src/widgets/mainwindow.h"
#include <QApplication>
#include <QDebug>

#include "redis_client/RedisClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    liana::RedisClient client("127.0.0.1:6789");

    qDebug() << client.isConnected() << endl;

    return a.exec();
}
