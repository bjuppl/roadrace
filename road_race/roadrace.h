#ifndef ROADRACE_H
#define ROADRACE_H
#include "network.h"
#include "title.h"
#include <QMainWindow>
#include <QSignalMapper>
namespace Ui {
class RoadRace;
}
class SquareLabel;
class RoadRace : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoadRace(QWidget *parent = 0);
    ~RoadRace();
    //title *child;
private slots:
    void on_btnStuff_clicked();
    void dataReceived();
    void serverDisconnected();
    void loadFile();

    void on_btnOpenGame_clicked();
    void labelClicked();
private:
    Ui::RoadRace *ui;
    QTcpSocket *server;
    QSignalMapper *signalMapper;
};

#endif // ROADRACE_H
