#include "roadrace.h"
#include "ui_roadrace.h"
#include "gamefile.h"
#include "gamemodel.h"
#include "gui.h"
#include "cheater.h"
#include "multiplayer.h"
#include "square.h"
#include "joiner.h"
#include <QLabel>
#include <QMessageBox>
#include "levelmanager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QDebug>
class Game;
class GameFileManager;
class GuiManager;

RoadRace::RoadRace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoadRace)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &RoadRace::dataReceived);
   connect(socket, &QTcpSocket::disconnected, this, &RoadRace::serverDisconnected);
   connect(ui->btnConnect,SIGNAL(clicked()),this,SLOT(connect_server()));
   connect(ui->btnSendToServer,SIGNAL(clicked()),this,SLOT(send()));
    connect(ui->cheatBtn,SIGNAL(clicked()),this,SLOT(openCheat()));
    connect(ui->testBtn,SIGNAL(clicked()),this,SLOT(openMulti()));
    connect(ui->joinBtn,SIGNAL(clicked()),this,SLOT(openJoin()));
}

//destructor
RoadRace::~RoadRace()
{
    delete ui;
}
//handle the btnStuff clicked event
void RoadRace::on_btnStuff_clicked()
{
    if (ui->EsyBtn->isChecked() || ui->MedBtn->isChecked() || ui->HardBtn->isChecked()){
    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );

    Game::instance().setGameLoader(
          new GameFileManager(
              LevelManager::instance().getLevel("test")
         )
     );

    GuiManager::instance().init();

    Updater::instance().start();
    //sets a difficulty based on the radio button
   GuiManager::instance().newDiff();
    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

    ui->btnStuff->setDisabled(true);
    ui->tst2Btn->setDisabled(true);
    }
    else{
        QMessageBox::information(ui->centralWidget,"Alert","You did not select a difficulty.");
    }
}
//receive data from the serveer
void RoadRace::dataReceived() {
   const QString gamestr = "RoadRaceDoc";
   QString str;
   bool launch;
   vector<QString> proc;
        while (socket->canReadLine()) {
             str = socket->readLine();
           if(str.at(0) == 'R' && str.at(5) == 'a'){
            launch = true;
           }
            ui->txtServerOutput->insertHtml(str + "\n");
           proc.push_back(str);

        }
    if(launch == true){
             GuiManager::instance().setUi( ui );
            LevelManager::instance().prepSquares(proc);

        }
      /*  else{
            Network::instance().actionHandler(str);
        }*/
}



//handles a client disconnecting from a server
void RoadRace::serverDisconnected()
{
     //ui->statusBar->showMessage("Disconnected.");
     //ui->btnConnect->setEnabled(true);
}

void RoadRace::connect_server()
{
    //QMessageBox::critical(this, "Uh oh", "Please specify name of chat server.");

    QString hostname = ui->iptServerName->text();
    if (hostname.size() == 0) {
        QMessageBox::critical(this, "Uh oh", "Please specify name of chat server.");
        return;
    }
    socket->connectToHost(hostname, 3141);
    if (!socket->waitForConnected())  {
        QMessageBox::critical(this, "Uh oh", "Unable to connect to server.");
        return;
    }

    ui->statusBar->showMessage("Connected.");
    ui->btnConnect->setEnabled(false);
    ui->iptServerMsg->setFocus();
    Game::instance().setIsLocalGame(true);
}


void RoadRace::send()
{

  /* // QString username = ui->ipt//->text();
    QString msg = ui->iptServerMsg->toPlainText();
    if (Game::instance().getCurPlayer() != nullptr) {
       /* std::string name = Game::instance().getCurPlayer() == NULL ?
                    "[No player]" :
                    Game::instance().getCurPlayer()->getName();
*/
    /*string name = Game::instance().getCurPlayer()->getName();

        msg = QString::fromStdString(name) + ": " + ui->iptServerMsg->toPlainText() + "\n";
        //QMessageBox::about(this,"We are sending this",msg);

    QString msg = ui->iptServerMsg->toPlainText();
    if (Game::instance().getCurPlayer() != nullptr) {
        ui->iptServerMsg->toPlainText() + "\n";

    } else {
        if(msg.size() > 0){
            msg += ui->iptServerMsg->toPlainText() + "\n";
        }
        else{
        return;
        }
    }*/
    QString msg = ui->iptServerMsg->toPlainText();
    ui->iptServerMsg->setText("");
   qDebug() << msg;
    socket->write(msg.toLocal8Bit());


   ui->iptServerMsg->setFocus();
}

void RoadRace::actionSender(QString msgstr){
    if(msgstr.size() > 0){
        socket->write(msgstr.toLocal8Bit());
    }
    else{
        return;
    }
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
if (ui->EsyBtn->isChecked() || ui->MedBtn->isChecked() || ui->HardBtn->isChecked()){
    std::string fileName = ui->iptGameFileName->text().toStdString();

    //Open a game with the properties in the given file
    Game::instance().setGameLoader(GameFileManager::fromFile(fileName));

    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );
    GuiManager::instance().init();

    Updater::instance().start();
    //sets a difficulty based on the radio button
   GuiManager::instance().newDiff();
    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

    ui->btnStuff->setDisabled(true);
    ui->tst2Btn->setDisabled(true);

}
    else{
        QMessageBox::information(ui->centralWidget,"Alert","You did not specify a difficulty!",0,0);
    }

       }

void RoadRace::on_helpBtn_clicked(){
 QMessageBox::information(ui->btnStuff,"Help Screen","The object of the game is to reach the castle square. By clicking a square, if you have one adjacent or touching with an apppropriate strucure you will take ownership of the square."
                                                                                         "\n"
                                                                                         "The key for which square gives which resource and requires what structure is as follows:\n"
                                                                                         "\n"
                                                                                         "Forest squares can be deforested or 75 water and 100 gold. They give Wood as a resource. Look for the squares which resemble camoflauge.\n"
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
                                                                                         "The more of a certain square you possess, the of that resource you get. For example owning two river squares gives 30 water per tick on easy versus just 15 for one square."
                                                                                         "\n"
                                                                                         "Files are saved as savefile.rr to your roadrace folder upon clicking the save button, and you can set the number of resouces you currently own with Cheater..."
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
void RoadRace::openMulti(){
    if(ui->btnConnect->isEnabled() == false){
    static multiplayer *multi1 = new multiplayer(this);
    multi1->show();
    multi1->activateWindow();
    multi1->raise();
    Game::instance().setIsLocalGame(false);
     GuiManager::instance().setUi( ui );
    }
    else{
        QMessageBox::information(ui->btnConnect,"Alert","Please find a server!",0,0);
    }

}

void RoadRace::on_SaveBtn_clicked()
{
    if (Game::instance().getGameLoader() != nullptr){
    string output = Game::instance().getGameLoader()->toGameFile();
    ofstream outfile("savefile.rr");
    outfile << output;
    outfile.close();
    }
}
void RoadRace::on_tst2Btn_clicked()
{
if (ui->EsyBtn->isChecked() || ui->MedBtn->isChecked() || ui->HardBtn->isChecked()){
    //Give our GUI manager access to ui
    GuiManager::instance().setUi( ui );

    Game::instance().setGameLoader(
          new GameFileManager(
              LevelManager::instance().getLevel("seven")
         )
     );

    GuiManager::instance().init();

    Updater::instance().start();
    //sets a difficulty based on the radio button, easy if nothing else is pressed
   GuiManager::instance().newDiff();
    std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

    ui->btnStuff->setDisabled(true);
    ui->tst2Btn->setDisabled(true);
}
    else{
        QMessageBox::information(ui->centralWidget,"Alert","You did not specify a difficulty!",0,0);
    }
}

void RoadRace::on_RanBtn_clicked()
{
    if (ui->EsyBtn->isChecked() || ui->MedBtn->isChecked() || ui->HardBtn->isChecked()){
        //Give our GUI manager access to ui
        GuiManager::instance().setUi( ui );

        Game::instance().setGameLoader(
              new GameFileManager(
                  LevelManager::instance().getLevel("randomfile")
             )
         );

        GuiManager::instance().init();

        Updater::instance().start();
        //sets a difficulty based on the radio button
       GuiManager::instance().newDiff();
        std::cout << Game::instance().getGameLoader()->toGameFile() << std::endl;

        ui->btnStuff->setDisabled(true);
        ui->tst2Btn->setDisabled(true);

    }
        else{
            QMessageBox::information(ui->centralWidget,"Alert","You did not specify a difficulty!",0,0);
        }
}

void RoadRace::openJoin(){
    if(ui->btnConnect->isEnabled() == false){
    static joiner *multi1 = new joiner(this);
    multi1->show();
    multi1->activateWindow();
    multi1->raise();
    Game::instance().setIsLocalGame(false);
    GuiManager::instance().setUi( ui );
    }
    else{
        QMessageBox::information(ui->btnConnect,"Alert","Please find a server!",0,0);
    }

}

void RoadRace::on_joinBtn_clicked()
{

}
