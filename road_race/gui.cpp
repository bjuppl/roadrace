#include "gui.h"
#include "roadrace.h"
#include "gamemodel.h"
#include "ui_roadrace.h"
#include "square.h"
#include "player.h"
#include "sound.h"
#include <QLabel>
#include <QMessageBox>

class Square;
class Player;

GuiManager *GuiManager::instance_ = NULL;

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

void GuiManager::init() {
    fillResourceList();
    generateSquareGrid();
}

void GuiManager::fillResourceList(){
    if ( Game::instance().getCurPlayer() == NULL ) {
        std::cout << "There is no current player. Oopsies!" <<std::endl;
        return;
    }
    int w = Game::instance().getCurPlayer()->getGold();
    int x = Game::instance().getCurPlayer()->getWater();
    int y = Game::instance().getCurPlayer()->getWood();
    int z = Game::instance().getCurPlayer()->getStone();
    ui->Go1->setText(QString::fromStdString(to_string(Game::instance().getCurPlayer()->getGold())));
    ui->Wa1->setText(QString::fromStdString(to_string(Game::instance().getCurPlayer()->getWater())));
    ui->wo1->setText(QString::fromStdString(to_string(Game::instance().getCurPlayer()->getWood())));
    ui->Sto1->setText(QString::fromStdString(to_string(z)));

}

void GuiManager::generateSquareGrid() {

    std::cout << getUi()->label->text().toStdString() << std::endl;


    ui->gameLayout->setContentsMargins(100,100,100,100);
    vector<vector<Square*>> squaresList = Game::instance().getSquares();


    vector<vector<Square*>> squares = Game::instance().getSquares();

    if ( squares.size() == 0) {
        return;
    }


    int border=5;
    int size = ui->gridLayoutWidget->width()/squares.size()/2;

    Square::setSize(size);
    Square::setBorder(border);

    for(size_t index = 0;index<squares.size();index++){
        for (size_t sub_index = 0; sub_index <squares.at(index).size(); sub_index++ ) {

            Square *proc = squares.at(index).at(sub_index);

            SquareLabel *lbl = new SquareLabel(proc,ui->gridLayoutWidget);

            proc->setLabel(lbl);
            QSize size1(size,size);
            QPixmap map = setmap(proc, size1);
            lbl->setPixmap(map);
            lbl->setFixedHeight(size);
            lbl->setFixedWidth(size);
            Player *owner = proc->getOwner();
            std::string color = owner == NULL ? "black" : owner->getColor();
            lbl->setStyleSheet("border:" + QString::fromStdString(to_string(border)) +  "px solid " + QString::fromStdString(color) + ";\n");
            ui->gameLayout->addWidget(lbl,index,sub_index,0);


            proc->setX(index);
            proc->setY(sub_index);
            lbl->show();
        }
        //ui->gameLayout->set(index,size);
        //ui->gameLayout->setRowMinimumHeight(index,size);

    }
    ui->gameLayout->setSpacing(0);
}




QPixmap GuiManager::setmap(Square *sq, QSize size){
    string image = sq->getImage();

    if(sq->getAddition() == "No")
    {
        if(image == "Fo"){
            QPixmap map(":/forrest");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Ca"){
            QPixmap map(":/canyon");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Ri"){
            QPixmap map(":/water");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if (image == "Mo"){
            QPixmap map(":/mountain");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Pl"){
            QPixmap map(":/grass");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Wi"){
            QPixmap map(":/win");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Sw"){
            QPixmap map(":/swamp");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "La"){
            QPixmap map(":/lava");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
    } else {
        if(image == "Fo"){
            QPixmap map(":/cleared");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Ca"){
            QPixmap map(":/bridge");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Ri"){
            QPixmap map(":/boat");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if (image == "Mo"){
            QPixmap map(":/tunnel");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Pl"){
            QPixmap map(":/grass");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Wi"){
            QPixmap map(":/win");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
        if(image == "Sw"){
            QPixmap map(":/grass");
            QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
            return result;
        }
       if(image == "La"){
           QPixmap map(":/bridge");
           QPixmap result = map.scaled(size, Qt::KeepAspectRatio);
           return result;

       }
}

}

void GuiManager::newDiff(){
    if(ui->EsyBtn->isChecked()){
        string easy = "Ez";
        Game::instance().setDiff(easy);
    }
    else if(ui->MedBtn->isChecked()){
        string medium = "Md";
        Game::instance().setDiff(medium);
    }
    else if(ui->HardBtn->isChecked()){
        string hard = "Ha";
        Game::instance().setDiff(hard);}
    else{
        string easy = "Ez";
        Game::instance().setDiff(easy);}}


void GuiManager::BuildStruct(Square *proc){
    if(proc->getAddition() == "No" && proc->getType() != "Pl"){
    QMessageBox::StandardButton canBuild;
    canBuild = QMessageBox::question(GuiManager::instance().getUi()->gridLayoutWidget,"You clicked one of your own squares!","Build a structure?",QMessageBox::Yes|QMessageBox::No);
    if (canBuild == QMessageBox::Yes){
     Player *name = proc->getOwner();
     string type = proc->getType();
     Structure *struc = Game::instance().resourceCheck(name,type);
     if(struc != nullptr){
     proc->setStruct(struc);
     proc->setAddition(struc->shortName);
      Sound::instance().playSound(":/constructionSound",1);
     if(struc->shortName == "Ha"){
         Game::instance().setVolc(false);
     }
     }
    else{


         QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You don't have enough resources!",0);

     }
}
}

}
void GuiManager::endGame(SquareLabel* x)
{
    Updater::instance().stop();
    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Congratualtions!!","You have won the game! But can you do it again?.",0,0);
}








void GuiManager::on_btnSendToServer_clicked()
{
    //window->send();
}

void GuiManager::on_btnConnect_clicked()
{

    //window->connect_server();
}

void GuiManager::on_testBtn_clicked()
{

}

