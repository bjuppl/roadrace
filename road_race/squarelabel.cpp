#include "squarelabel.h"
#include "gamemodel.h"
#include "gui.h"
#include "sound.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>

using namespace std;


void SquareLabel::mousePressEvent(QMouseEvent *ev){

    vector<vector<Square*>> squareList = Game::instance().getSquares();
    Square *proc = square;
    //handle if square is not currently owned
    if (proc->getOwner() == nullptr){
        size_t x = proc->getX();
        size_t y = proc->getY();
        //use for comparison against x and y
        int height = Game::instance().getHeight();
        int width = Game::instance().getWidth();
        // alias x-1

        int x2 = (x-1);

        QString owner;
        //handles cases in which a square is against the left most bracket
        if((y) == 0){

            Square *c1;
            Square *c2;
            Square *c3;
            vector<Square*> list1;
            vector<Square*> list2;
            vector<Square*> list3;
            bool valid = false;
            bool buildErr = false;
            Player *newowner;
            //normal squares
            if(x >= 0 && x != squareList.size()){
                list1 = squareList.at(x);
                list2 = squareList.at(x2);
                c1 = list1.at(0);
                c2 = list2.at(0);
                c3 = list1.at(1);

            }
            //handle bottom left corner
            else{
                list2 = squareList.at(x2);
                list3 = squareList.at(x-1);
                c1=nullptr;
                c2 = list2.at(0);
                c3 = list3.at(1);
            }
            if((c1!= nullptr) && (c1->getOwner() != nullptr) &&(c1->getOwner() == Game::instance().getCurPlayer())){
                if (proc->canGet(c1)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr && valid == false)&&(c2->getOwner() == Game::instance().getCurPlayer())){
                newowner = c2->getOwner();
                if (proc->canGet(c2)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            else if((c3->getOwner() != nullptr) && (valid == false) &&(c3->getOwner() == Game::instance().getCurPlayer())){
                newowner = c3->getOwner();
                if (proc->canGet(c3)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if(valid == false){
                if(buildErr){
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not have a valid road to over come the obstacle in your way.",0,0);
                }
                else{
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not currently own a square adjacent to this one.",0,0);
                }
            }
            if(valid == true){
                //helps with calling again
                c1=nullptr;
                c2=nullptr;
                c3=nullptr;
                if(proc->getType() == "Sw"){
                newowner->setSwamped(true);
                }
                proc->setOwner(newowner);
                owner = QString::fromUtf8(newowner->getName().c_str());
            }
        }
        //handles the right most edge
        else if(y == (width-1)){

            Square *c1;
            Square *c2;
            Square *c3;
            vector<Square*> list1;
            vector<Square*> list2;
            vector<Square*> list3;
            Player *newowner;
            bool valid = false;
            bool buildErr = false;
            //normal processing
            if(x > 0 && (x != squareList.size()-1)){
                list1 = squareList.at(x+1);
                if(x2 >= 0){
                    list2 = squareList.at(x2);
                    c2 = list2.at(y);
                }
                list3 = squareList.at(x);
                c1 = list1.at(y);
                c3 = list3.at(y-1);
            }
            //bottom & top right corners
            else{
                if(x2 == -1){
                    list2 = squareList.at(x+1);
                }
                else{
                    list2 = squareList.at(x2);
                }
                list3 = squareList.at(x);
                c1=nullptr;
                c2 = list2.at(y);
                c3 = list3.at(y-1);
            }
            if((c1!= nullptr) && (c1->getOwner() != nullptr)&&(c1->getOwner() == Game::instance().getCurPlayer())){
                newowner = c1->getOwner();
                if (proc->canGet(c1)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr) && (valid == false) &&(c2->getOwner() == Game::instance().getCurPlayer())){
                newowner = c2->getOwner();
                if (proc->canGet(c2)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            else if((c3->getOwner() != nullptr) && (valid == false) &&(c3->getOwner() == Game::instance().getCurPlayer())){
                newowner = c3->getOwner();
                if (proc->canGet(c3)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if(valid == false){
                if(buildErr){
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not have a valid road to over come the obstacle in your way.",0,0);
                }
                else{
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not currently own a square adjacent to this one.",0,0);
                }
            }
            if(valid == true){
                c1=nullptr;
                c2=nullptr;
                c3=nullptr;
                if(proc->getType() == "Sw"){
                    newowner->setSwamped(true);
                }
                proc->setOwner(newowner);
                owner = QString::fromStdString(newowner->getName());
            }
        }
        //handles inner squares
        else {
            Square *c1;
            Square *c2;
            Square *c3;
            Square *c4;
            vector<Square*> list1;
            vector<Square*> list2;
            vector<Square*> list3;
            Player *newowner;
            bool valid = false;
            bool buildErr = false;
            //topmost
            if (x == 0){
                list1 = squareList.at(x);
                list2 = squareList.at(x+1);
                c1 = list1.at(y+1);
                c2 = list1.at(y-1);
                c3 = list2.at(y);
                c4 = nullptr;
            }
            //bottom most
            else if (x == height-1){
                list1 = squareList.at(x);
                list2 = squareList.at(x-1);
                c1 = list1.at(y+1);
                c2 = list1.at(y-1);
                c3 = list2.at(y);
                c4 = nullptr;
            }
            //normal
            else{
                list1 = squareList.at(x);
                list2 = squareList.at(x+1);
                list3 = squareList.at(x-1);
                c1 = list1.at(y+1);
                c2 = list1.at(y-1);
                c3 = list2.at(y);
                c4 = list3.at(y);
            }
            if((c1!= nullptr) && (c1->getOwner() != nullptr)&&(c1->getOwner() == Game::instance().getCurPlayer())){
                newowner = c1->getOwner();
                if (proc->canGet(c1)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if((c2!= nullptr) && (c2->getOwner() != nullptr) && (valid == false)&&(c2->getOwner() == Game::instance().getCurPlayer())){
                newowner = c2->getOwner();
                if (proc->canGet(c2)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if((c3!= nullptr) && (c3->getOwner() != nullptr && valid == false)&&(c3->getOwner() == Game::instance().getCurPlayer())){
                newowner = c3->getOwner();
                if (proc->canGet(c3)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if((c4!= nullptr) && (c4->getOwner() != nullptr) && (valid == false) &&(c4->getOwner() == Game::instance().getCurPlayer())){
                newowner = c4->getOwner();
                if (proc->canGet(c4)){
                    valid = true;
                }
                else{buildErr = true;}
            }
            if(valid == false){
                if(buildErr){
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not have a valid road to over come the obstacle in your way.",0,0);
                }
                else{
                    QMessageBox::information(GuiManager::instance().getUi()->gridLayoutWidget,"Alert!","You do not currently own a square adjacent to this one.",0,0);
                }
            }
            if(valid == true){
                c1=nullptr;
                c2=nullptr;
                c3=nullptr;
                c4=nullptr;
                proc->setOwner(newowner);
                if(proc->getType() == "Sw"){
                    newowner->setSwamped(true);
                }
                if ( newowner != nullptr ) {
                    owner = QString::fromUtf8(newowner->getName().c_str());
                }

            }
        }
        if(owner != nullptr && (proc->getOwner()== Game::instance().getCurPlayer())){
            //set text/border
            this->setText(owner);
            this->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));

            if(this->square->getType() == "Wi") {
                GuiManager::instance().endGame(this);
            }
            this->setText(owner);
            this->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
            string action = "New Owner";
            string details;
            int procx = proc->getX();
            int procy = proc->getY();
            details += to_string(procx) + " " + to_string(procy) + " " + proc->getOwner()->getName();
            //qDebug() << QString::fromStdString(details);
            QString msg = QString::fromStdString(Network::instance().ActionReciever(action,details));
            GuiManager::instance().getWindow()->actionSender(msg);
            Sound::instance().playSound(":/acquireSound",1);


        }
    }
    else{
        //handle owned squares
        GuiManager::instance().BuildStruct(square);
        string action = "New Struct";
        string details;
        int procx = square->getX();
        int procy = square->getY();
        details += to_string(procx) + " " + to_string(procy) + " " + square->getAddition() + " " + square->getOwner()->getName();
        QString msg = QString::fromStdString(Network::instance().ActionReciever(action,details));
        GuiManager::instance().getWindow()->actionSender(msg);
    }

    if(this->square->getAddition() == "De")
    {
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/cleared");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    if(this->square->getAddition() == "Bo")
    {
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/boat");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    if(this->square->getAddition() == "Br")
    {
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/bridge");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    if(this->square->getAddition() == "Tu")
    {
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/tunnel");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    if(this->square->getAddition() == "Cl"){
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/grass");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    if(this->square->getAddition() == "Ha"){
        vector<vector<Square*>> squares = Game::instance().getSquares();
        int size = GuiManager::instance().getUi()->gridLayoutWidget->width()/squares.size()/2;
        QPixmap map(":/bridge");
        this->setPixmap(map.scaled(QSize(size,size), Qt::KeepAspectRatio));
    }
    emit clicked();

}
void SquareLabel::mouseMoveEvent(QMouseEvent *ev){

}

void SquareLabel::enterEvent(QHoverEvent *event){

    if(square->getOwner() != nullptr){
        QString owner = QString::fromUtf8(square->getOwner()->getName().c_str());
        this->setText(owner);
    }
    else{
        this->setText("Unowned");
    }
}


QPixmap SquareLabel::setmap(string image){

    QPixmap map(":/grass");
    QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
    return result;
    /*if(image == "Fo"){
        QPixmap map(":/forrest");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);

        return result;
    }
    if(image == "Ca"){
        QPixmap map(":/canyon");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Ri"){
        QPixmap map(":/water");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
        return result;
    }
    if (image == "Mo"){
        QPixmap map(":/mountain");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Pl"){
        QPixmap map(":/grass");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Wi"){
        QPixmap map(":/win");
        QPixmap result = map.scaled(QSize(Square::getSize(),Square::getSize()), Qt::KeepAspectRatio);
        return result;
    */

}
void SquareLabel::leaveEvent(QHoverEvent *event){
    QSize size(square->getSize(),square->getSize());

    QPixmap map =  GuiManager::instance().setmap(square,size);
    this->setPixmap(map);
}

bool SquareLabel::event(QEvent *e){
    switch(e->type()){
    case QEvent::HoverEnter:
        enterEvent(static_cast<QHoverEvent*>(e));
        return true;
        break;
    case QEvent::HoverLeave:
        leaveEvent(static_cast<QHoverEvent*>(e));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(e);
}

//takes the additoin of <prev> and returns true if a user has the appropriate sturcture to
//obtain the square. Otherwise returns false.
bool Square::canGet(Square *prev){
    if (prev->getType() == "Ri"){
        if(prev->getAddition() == "Bo"){
            return true;
        }
        else{
            return false;
        }
    }
    if(prev->getType() == "Mo"){
        if(prev->getAddition() == "Tu"){
            return true;
        }
        else{
            return false;
        }
    }
    if(prev->getType() == "Ca"){
        if(prev->getAddition() == "Br"){
            return true;
        }
        else{
            return false;
        }
    }
    if(prev->getType() == "Fo"){
        if(prev->getAddition() == "De"){
            return true;
        }
        else{
            return false;
        }
    }
    if(prev->getType() == "La"){
        if(prev->getAddition() == "Ha"){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }

}


void SquareLabel::action(){

}
