#ifndef ROADRACE_H
#define ROADRACE_H
#include "network.h"
#include <QMainWindow>
#include <QSignalMapper>
#include <QTcpSocket>
#include "cheater.h"
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
    void actionSender(QString msgstr);
    //title *child;
private slots:
    void on_btnStuff_clicked();

    void dataReceived();
    void serverDisconnected();

    void connect_server();
    void send();

    void loadFile();

    void on_btnOpenGame_clicked();
    void labelClicked();
    void on_helpBtn_clicked();
    void on_cheatBtn_clicked();
    void openCheat();
    void on_SaveBtn_clicked();
    void on_tst2Btn_clicked();
    void on_RanBtn_clicked();
    void openMulti();

    void openJoin();
    void on_joinBtn_clicked();

private:
    Ui::RoadRace *ui;
    QTcpSocket *socket;
     QSignalMapper *signalMapper;
};

#endif // ROADRACE_H
