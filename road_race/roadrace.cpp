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
          QString wood;
          QString gold;
          QString stone;
          QString Water;
          wood += proc->getWood();
          Water += proc->getWater();
          gold  += proc->getGold();
          stone += proc->getStone();
        if(i=0){
            msg.fromUtf8(name.c_str());
            ui->player1->setText("Player 1:");
            ui->wo1->setText(wood);
            ui->Go1->setText(gold);
            ui->Sto1->setText(stone);
            ui->Wa1->setText(Water);
            ui->name1->setText(msg);
        }
        if(i=1){
            msg.fromUtf8(name.c_str());
            ui->player2->setText("Player 2:");
            ui->wo2->setText(wood);
            ui->Go2->setText(gold);
            ui->Sto2->setText(stone);
            ui->Wa2->setText(Water);
            ui->name2->setText(msg);
        }
        if(i=2){
            msg.fromUtf8(name.c_str());
            ui->player3->setText("Player 3:");
            ui->wo3->setText(wood);
            ui->Go3->setText(gold);
            ui->Sto3->setText(stone);
            ui->Wa3->setText(Water);
            ui->name3->setText(msg);
        }
        if(i=3){
            msg.fromUtf8(name.c_str());
            ui->player4->setText("Player 4:");
            ui->wo4->setText(wood);
            ui->Go4->setText(gold);
            ui->Sto4->setText(stone);
            ui->Wa4->setText(Water);
            ui->name4->setText(msg);
        }
    }
}
