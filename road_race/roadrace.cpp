#include "roadrace.h"
#include "ui_roadrace.h"

RoadRace::RoadRace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoadRace)
{
    ui->setupUi(this);

    server = new QTcpSocket(this);
    connect(server, &QTcpSocket::readyRead, this, &RoadRace::dataReceived);
    connect(server, &QTcpSocket::disconnected, this, &RoadRace::serverDisconnected);
}

RoadRace::~RoadRace()
{
    delete ui;
}

void RoadRace::on_btnStuff_clicked()
{

}

void RoadRace::dataReceived() {

    while (server->canReadLine()) {
        QString str = server->readLine();

        //ui->txtChat->insertHtml("<b>" + username + "</b>: " + msg + "<br><br>");
    }

}

void RoadRace::serverDisconnected()
{
     ui->statusBar->showMessage("Disconnected.");
     //ui->btnConnect->setEnabled(true);
}

