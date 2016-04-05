#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include "network.h"

#include <QDialog>
#include <QSignalMapper>
#include <QTcpSocket>
namespace Ui {
class multiplayer;
}

class multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit multiplayer(QWidget *parent = 0);
    ~multiplayer();

private slots:
    void on_voidBtn_clicked();

    void on_okBtn_clicked();
    void connect_server();
    void data_received();
    //void serverDisconnected();
private:
    Ui::multiplayer *ui;
    QTcpSocket *socket;
    QSignalMapper *signalMapper;
};

#endif // MULTIPLAYER_H
