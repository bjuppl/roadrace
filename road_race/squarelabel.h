#ifndef SQUARELABEL_H
#define SQUARELABEL_H

#include <string>
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include "player.h"
#include <QMouseEvent>
#include <QGridLayout>
#include <QMainWindow>
#include <QHoverEvent>

#include "square.h"

using namespace std;

class Square;

class SquareLabel : public QLabel{
    Q_OBJECT

    Square *square;
    bool mouseTracking;
public:
    explicit SquareLabel (Square *square_, QWidget *parent): QLabel(parent), square(square_) {
        setMouseTracking(true);
        this->setAttribute(Qt::WA_Hover,true);
        connect(this,SIGNAL(clicked()),this,SLOT(labelClicked()));
    }
   void mousePressEvent(QMouseEvent *ev);
   void mouseMoveEvent(QMouseEvent *ev);
   void enterEvent(QHoverEvent *event);
   void leaveEvent(QHoverEvent *event);
   bool event(QEvent *e);
   QPixmap setmap(string image);
   void endGame();
   void updateMap(SquareLabel *lbl);
   /*void setFrame(QFrame *f){
       frame = f;
   }
   void setColor(QPalette *p){
       color = p;
   }*/
   /*QPalette* getColor(){return color;}
   QFrame* getFrame(){return frame;}*/
   ~SquareLabel(){
       //delete frame;
       //delete color;
   }

private slots:
    void labelClicked(){

    }

signals:
    void clicked();
    void hovered();

};


#endif // SQUARELABEL_H
