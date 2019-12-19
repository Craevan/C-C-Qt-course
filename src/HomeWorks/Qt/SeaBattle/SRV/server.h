#ifndef SERVER_H
#define SERVER_H

#include "field.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>



enum ClientStatus {
    CONNECTED = 0, AUTHORIZED, READY, WAITING_FOT_THE_STEP, MAKING_STEP
};

struct Client {
    QTcpSocket* socket;
    ClientStatus status;
    QMap<int, Client>::iterator gaming;
    void send(const QString& cmd);
    Field field;
};

typedef QMap<int, Client> clientList;

class Server
{
public:
    Server();
private:
    QTcpServer *server;
    clientList clients;
    QTimer *timer;
};

#endif // SERVER_H
