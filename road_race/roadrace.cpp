#include "roadrace.h"
#include "ui_roadrace.h"
#include "gamefile.h"
#include "gamemodel.h"
#include "gui.h"

#include "square.h"
#include <QLabel>

#include "levelmanager.h"

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

    GuiManager::instance().init();

    Updater::instance().start();
    //sets a difficulty based on the radio button, easy if nothing else is pressed
   GuiManager::instance().newDiff();
    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

    ui->btnStuff->setDisabled(true);

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

    //update resource list
    GuiManager::instance().fillResourceList();

    //Set the timer ticking!
    Updater::instance().start();


}


void RoadRace::on_btnOpenGame_clicked()
{

    std::string fileName = ui->iptGameFileName->text().toStdString();

    //Open a game with the properties in the given file
    Game::instance().setGameLoader(GameFileManager::fromFile(fileName));

    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );
    GuiManager::instance().init();

    Updater::instance().start();
    //sets a difficulty based on the radio button, easy if nothing else is pressed
   GuiManager::instance().newDiff();
    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

    ui->btnStuff->setDisabled(true);

       this->loadFile();


       }



void RoadRace::labelClicked(){


}
