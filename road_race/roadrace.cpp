#include "roadrace.h"
#include "ui_roadrace.h"
#include "gamefile.h"
#include "gamemodel.h"
#include "gui.h"

#include "square.h"
#include <QLabel>

#include "levelmanager.h"

>>>>>>> upstream/master
class Game;
class GameFileManager;
class GuiManager;

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
    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );

    Game::instance().setGameLoader(
          new GameFileManager(
              LevelManager::instance().getLevel("test")
         )
     );

    GuiManager::instance().generateSquareGrid();

    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;


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
    //Show the squares
    GuiManager::instance().generateSquareGrid();


    vector<Player*> players = Game::instance().getPlayerList();

     size_t i = 0;
    while(i<players.size()){
        Player *proc = players.at(i);
        string name = proc->getName();
          QString msg;
          QString wood;
          QString gold;
          QString stone;
          QString Water;
           int woodint = proc->getWood();
           wood = QString::number(woodint);
           int waterint = proc->getWater();
           Water = QString::number(waterint);
           int goldint = proc->getGold();
           int stoneint = proc->getStone();

            gold = QString::number(goldint);
           stone = QString::number(stoneint);
        if(i==0){
            msg = QString::fromUtf8(name.c_str());
            ui->player1->setText("Player 1:");
            ui->wo1->setText(wood);
            ui->Go1->setText(gold);
            ui->Sto1->setText(stone);
            ui->Wa1->setText(Water);
            ui->name1->setText(msg);
        }
        if(i==1){
            msg = QString::fromUtf8(name.c_str());
            ui->player2->setText("Player 2:");
            ui->wo2->setText(wood);
            ui->Go2->setText(gold);
            ui->Sto2->setText(stone);
            ui->Wa2->setText(Water);
            ui->name2->setText(msg);
        }
        if(i==2){
            msg = QString::fromUtf8(name.c_str());
            ui->player3->setText("Player 3:");
            ui->wo3->setText(wood);
            ui->Go3->setText(gold);
            ui->Sto3->setText(stone);
            ui->Wa3->setText(Water);
            ui->name3->setText(msg);
        }
        if(i==3){
            msg = QString::fromUtf8(name.c_str());
            ui->player4->setText("Player 4:");
            ui->wo4->setText(wood);
            ui->Go4->setText(gold);
            ui->Sto4->setText(stone);
            ui->Wa4->setText(Water);
            ui->name4->setText(msg);
        }
        msg="";
        i++;
    }

}


void RoadRace::on_btnOpenGame_clicked()
{

    std::string fileName = ui->iptGameFileName->text().toStdString();

    //Open a game with the properties in the given file
    Game::instance().setGameLoader(GameFileManager::fromFile(fileName));

    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );

       this->loadFile();

       
       }



void RoadRace::labelClicked(){
    SquareLabel *proc = dynamic_cast<SquareLabel*>(sender());

}
