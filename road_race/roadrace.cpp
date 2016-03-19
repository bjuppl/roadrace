#include "roadrace.h"
#include "ui_roadrace.h"
#include "gamefile.h"
#include "gamemodel.h"
#include "gui.h"
#include "cheater.h"
#include "square.h"
#include <QLabel>
#include <QMessageBox>
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
    connect(ui->cheatBtn,SIGNAL(clicked()),this,SLOT(openCheat()));
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

void RoadRace::on_helpBtn_clicked(){
 QMessageBox::information(ui->btnStuff,"Help Screen","The object of the game is to reach the castle square. By clicking a square, if you have one adjacent or touching with an apppropriate strucure you will take ownership of the square."
                                                                                         "\n"
                                                                                         "The key for which square gives which resource and requires what structure is as follows:\n"
                                                                                         "\n"
                                                                                         "Forest squares can be deforested or 75 water and 100 gold. They give Wood as a resource. Look for the squares with green leaves against a white backgroud.\n"
                                                                                         "\n"
                                                                                         "Canyon squares can have a bridge built for 300 stone and 100 wood. They give Gold as a resource. These brown squares resemble mesa rock.\n"
                                                                                         "\n"
                                                                                         "River squares can have a boat built for 200 water and 100 stone.They give Water as a resource. The distincitve blue of these squares should be obvious.\n"
                                                                                         "\n"
                                                                                         "Mountain squares can have a tunnel made for 50 stone, 50 wood, and 100 gold. They give Stone as a resource. These squares show their majestic grey cliffs.\n"
                                                                                         "\n"
                                                                                         "Plains squares give no resources and require no structures to traverse. The lush green grasslands look rather inviting.\n"
                                                                                         "\n"
                                                                                         "Resources are given at specific time intervals. The amount depends on the difficulty selected.\n"
                                                                                         "\n"
                                                                                         "The more of a certian square you possess, the of that resource you get. For example owning two river squares gives 30 water per tick on easy versus just 15 for one square."
                                                                                         "\n"
                                                                                         "Now go, and race to the finish!",0,0);
}
void RoadRace::labelClicked(){


}
void RoadRace::on_cheatBtn_clicked()
{

}
void RoadRace::openCheat(){
    static cheater *cheat1 = new cheater(this);
    cheat1->show();
    cheat1->activateWindow();
    cheat1->raise();
}
