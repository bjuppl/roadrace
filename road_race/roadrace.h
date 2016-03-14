#ifndef ROADRACE_H
#define ROADRACE_H
#include "network.h"
#include "title.h"
#include <QMainWindow>

namespace Ui {
class RoadRace;
}

class RoadRace : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoadRace(QWidget *parent = 0);
    ~RoadRace();
    title *child;
private slots:
    void on_btnStuff_clicked();
    void dataReceived();
    void serverDisconnected();
    void loadFile();

    void on_btnOpenGame_clicked();

private:
    Ui::RoadRace *ui;
    QTcpSocket *server;
};

#endif // ROADRACE_H
