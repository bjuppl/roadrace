#include "multiplayer.h"
#include "ui_multiplayer.h"
#include "gamemodel.h"
#include "gamefile.h"
#include "roadrace.h"
#include "gui.h"
#include "player.h"
#include "square.h"
#include <string>
#include <QMessageBox>
multiplayer::multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multiplayer)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(ui->okBtn,SIGNAL(clicked()),this,SLOT(connect_server()));
}

multiplayer::~multiplayer()
{
    delete ui;
}

void multiplayer::on_voidBtn_clicked()
{
    this->hide();
}

void multiplayer::on_okBtn_clicked()
{

}
void multiplayer::connect_server(){
    QString gameName = ui->nameBox->text();
    QString gamePass = ui->passBox->text();
    QString playerNumstr = ui->numBox->text();
    QString level;
    if (ui->fiveBtn->isChecked()){
        level = "five";
    }
    if(ui->sevBtn->isChecked()){
        level = "seven";
    }
    if(ui->randBtn->isChecked()){
        level = "random";
    }
    QString sendstr;
    sendstr += gameName + " " + gamePass + " " + playerNumstr + level;
    QString hostname = "localhost";
    if (hostname.size() == 0) {
        QMessageBox::critical(this, "Uh oh", "Please specify name of chat server.");
        return;
    }
    socket->connectToHost(hostname, 3141);
    if (!socket->waitForConnected())  {
        QMessageBox::critical(this, "Uh oh", "Unable to connect to server.");
        return;
    }
    socket->write(sendstr.toLocal8Bit());
    this->hide();
}
