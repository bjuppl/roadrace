#include "joiner.h"
#include "ui_joiner.h"
#include "gamemodel.h"
#include "player.h"
#include <QMessageBox>
#include <QTcpSocket>
#include <sstream>
joiner::joiner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joiner)
{
    ui->setupUi(this);
}

joiner::~joiner()
{
    delete ui;
}

void joiner::on_killBtn_clicked()
{
    this->hide();
}

void joiner::data_received() {

}

void joiner::on_joinBtn_clicked()
{
    socket = new QTcpSocket(this);
    QString gname = ui->gameBox->text();
    QString gpass = ui->passBox->text();
    QString pname = ui->nameBox->text();
    QString request;

    stringstream strm;
    strm << "join " << gname << "\n" << "password " <<  gpass << "\n" << "name " << pname << "\n";
    request = QString::fromStdString(strm.str());

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
    else{
        string plname = pname.toStdString();
        Player *pl1 = new Player(plname);
        pl1->setColor("yellow");
        vector<Player*> players;
        players.push_back(pl1);
        Game::instance().setPlayerList(players);
        Game::instance().setCurPlayer(pl1);
    socket->write(request.toLocal8Bit());
    this->hide();

    Network::instance().setSocket(socket);
    }
}
