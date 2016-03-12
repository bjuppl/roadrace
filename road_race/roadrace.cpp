#include "roadrace.h"
#include "ui_roadrace.h"
#include "gamefile.h"
#include "gamemodel.h"

class Game;
class GameFileManager;

RoadRace::RoadRace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoadRace)
{
    ui->setupUi(this);

    server = new QTcpSocket(this);
    connect(server, &QTcpSocket::readyRead, this, &RoadRace::dataReceived);
    connect(server, &QTcpSocket::disconnected, this, &RoadRace::serverDisconnected);
}
//destructor
RoadRace::~RoadRace()
{
    delete ui;
}
//handle the btnStuff clicked event
void RoadRace::on_btnStuff_clicked()
{

}
//receive data from the serveer
void RoadRace::dataReceived() {

    while (server->canReadLine()) {
        QString str = server->readLine();

        //ui->txtChat->insertHtml("<b>" + username + "</b>: " + msg + "<br><br>");
    }

}
//handles a client disconnecting from a server
void RoadRace::serverDisconnected()
{
     ui->statusBar->showMessage("Disconnected.");
     //ui->btnConnect->setEnabled(true);
}
void RoadRace::loadFile() {

}


void RoadRace::on_btnOpenGame_clicked()
{
    std::string fileName = ui->iptGameFileName->text().toStdString();

    Game::instance().setGameLoader(GameFileManager::fromFile(fileName));

    vector<Player*> players = Game::instance().getPlayerList();


    for(int i=0;i<players.size();i++){
        Player *proc = players.at(i);
        string name = proc->getName();
          QString msg;
        if(i=0){
            msg.fromUtf8(name.c_str());
            ui->player1->setText("Player 1:");

            ui->name1->setText(msg);
        }
        if(i=1){
            msg.fromUtf8(name.c_str());
            ui->player2->setText("Player 2:");

            ui->name2->setText(msg);
        }
        if(i=2){
            msg.fromUtf8(name.c_str());
            ui->player3->setText("Player 3:");

            ui->name3->setText(msg);
        }
        if(i=3){
            msg.fromUtf8(name.c_str());
            ui->player4->setText("Player 4:");

            ui->name4->setText(msg);
        }
    }
}
