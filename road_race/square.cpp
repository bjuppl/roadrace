#include "square.h"
#include "gamemodel.h"
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>

int Square::count = 0;

std::string Square::getResourceType() {
    // Pl = plain, Ri = river, Mo = mountain, Fo = forest, Ca = canyon
    if ( type == "Pl") {
        return "";
    } else if ( type == "Ri" ) {
        return "Wa";
    } else if ( type == "Mo" ) {
        return "St";
    } else if ( type == "Fo" ) {
        return "Wo";
    } else if ( type == "Ca") {
        return "Go";
    } else {
        return "";
    }
}


void SquareLabel::mousePressEvent(QMouseEvent *ev){

    vector<vector<Square*>> squareList = Game::instance().getSquares();
   int i = squareList.size();
    Square *proc = square;
    int x = this->x();
    if (proc->getOwner() == nullptr){
        int x = proc->getX();
        int y = proc->getY();
        int height = Game::instance().getHeight();
        int width = Game::instance().getWidth();
        QString owner;
        if((x-1) == 0){
            vector<Square*> list = squareList.at(0);
            Square *comp = list.at(0);
            Player *newowner = comp->getOwner();
            QPalette *color = this->getColor();
            this->getFrame()->setPalette(*color);
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
        }
        else if((x+1) <= width){
            Square *comp = Game::instance().getSquare(x-1,y);
            Square *comp2;
            Square *comp3;
            Player *newowner;
            if(Game::instance().getSquare(x,y+1) != nullptr){
              comp2 = Game::instance().getSquare(x,y+1);
            }
            if(Game::instance().getSquare(x,y-1) != nullptr){
             comp3 = Game::instance().getSquare(x,y-1);
            }
            if(comp->getOwner() != nullptr){
            newowner = comp->getOwner();
            }
            else if (comp2->getOwner() != nullptr){
                newowner = comp2->getOwner();
            }
            else {
                newowner = comp3->getOwner();
            }
            if (newowner != nullptr){
            proc->setOwner(newowner);
            owner = QString::fromUtf8(newowner->getName().c_str());
            }
            else{
                 QMessageBox::information(this,"Alert","You cannot claim this square!",0,1);
            }
        }
        else if((y-1) > 0){
            Square *comp = Game::instance().getSquare(x+1,y);
        }
        else if((y+1) <= height){
            Square *comp = Game::instance().getSquare(x+1,y);
             }
        this->setText(owner);
    }

    else{
            QString owner;
            owner = QString::fromUtf8(proc->getOwner()->getName().c_str());
            this->setText(owner);
    }
    emit clicked();
}
void SquareLabel::mouseMoveEvent(QMouseEvent *ev){

}
QPixmap SquareLabel::setmap(string image){


    if(image == "Fo"){
        QPixmap map(":/forrest");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);

        return result;
    }
    if(image == "Ca"){
        QPixmap map(":/canyon");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Ri"){
        QPixmap map(":/water");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if (image == "Mo"){
        QPixmap map(":/mountain");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Pl"){
        QPixmap map(":/grass");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
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
