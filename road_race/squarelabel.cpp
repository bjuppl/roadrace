#include "squarelabel.h"
#include "gamemodel.h"
#include "gui.h"
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
            if((c1!= nullptr) && (c1->getOwner() != nullptr)){
                newowner = c1->getOwner();
                valid = true;
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr)){
                newowner = c2->getOwner();
              valid = true;
            }
            else if(c3->getOwner() != nullptr){
                newowner = c3->getOwner();
                valid = true;
            }
            else{
                QMessageBox::information(this,"Alert!","You do not currently own a square adjacent to this one.",0,0);
            }if(valid == true){
                //helps with calling again
            c1=nullptr;
            c2=nullptr;
            c3=nullptr;
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
            if((c1!= nullptr) && (c1->getOwner() != nullptr)){
                newowner = c1->getOwner();
                valid = true;
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr)){
                newowner = c2->getOwner();
                valid = true;
            }
            else if(c3->getOwner() != nullptr){
                newowner = c3->getOwner();
                valid = true;
            }
            else{
                QMessageBox::information(this,"Alert!","You do not currently own a square adjacent to this one.",0,0);
            }
            if(valid == true){
            c1=nullptr;
            c2=nullptr;
            c3=nullptr;
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
            //topmost
            if (x == 0){
                list1 = squareList.at(x);
                list2 = squareList.at(x+1);
                c1 = list1.at(y+1);
                c2 = list1.at(y-1);
                c3 = list2.at(y);

            }
            //bottom most
            else if (x == height-1){
                list1 = squareList.at(x);
                list2 = squareList.at(x-1);
                c1 = list1.at(y+1);
                c2 = list1.at(y-1);
                c3 = list2.at(y);
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
            if((c1!= nullptr) && (c1->getOwner() != nullptr)){
                newowner = c1->getOwner();
                valid = true;
            }
            else if((c2!= nullptr) && (c2->getOwner() != nullptr)){
                newowner = c2->getOwner();
                valid = true;
            }
            else if((c3!= nullptr) && (c3->getOwner() != nullptr)){
                newowner = c3->getOwner();
                valid = true;
            }
            else if((c4!= nullptr) && (c4->getOwner() != nullptr)){
                newowner = c4->getOwner();
                valid = true;
            }
            else{
                QMessageBox::information(this,"Alert!","You do not currently own a square adjacent to this one.",0,0);
            }
            if(valid == true){
            c1=nullptr;
            c2=nullptr;
            c3=nullptr;
            c4=nullptr;
            proc->setOwner(newowner);
            if ( newowner != nullptr ) {
                owner = QString::fromUtf8(newowner->getName().c_str());
            }

        }
        }
        if(owner != nullptr){
<<<<<<< HEAD
            //set text/border
        this->setText(owner);
        this->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
=======
            if(this->square->getType() == "Wi") {
                QMessageBox::information(this,"Congratualtions!!","You have won the game! But can you do it again?.",0,0);
            }
            this->setText(owner);
            this->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
>>>>>>> upstream/master
        }


    }

    else{
        //handle owned squares until I decide what to do with them.
            QString owner;
            owner = QString::fromUtf8(proc->getOwner()->getName().c_str());
            this->setStyleSheet("border:" + QString::fromStdString(to_string(proc->getBorder())) + "px solid " + QString::fromStdString(proc->getOwner()->getColor()));
            this->setText(owner);
    }
    emit clicked();
}

void SquareLabel::mouseMoveEvent(QMouseEvent *ev){

}
QPixmap SquareLabel::setmap(string image){


    if(image == "Fo"){
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
    }

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
void SquareLabel::leaveEvent(QHoverEvent *event){
    QPixmap map = setmap(square->getImage());

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

bool Square::canGet(Square *prev){
    if (this->getType() == "Ri"){
        if(prev->getAddition() == "Bo"){
            return true;
        }
        else{
            return false;
        }
    }
    if(this->getType() == "Mo"){
        if(prev->getAddition() == "Tu"){
            return true;
        }
        else{
            return false;
        }
    }
    if(this->getType() == "Ca"){
        if(prev->getAddition() == "Br"){
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


