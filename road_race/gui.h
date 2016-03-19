#ifndef GUI_H
#define GUI_H

#include "ui_roadrace.h"
#include "roadrace.h"
#include "gamemodel.h"
#include "squarelabel.h"
#include "square.h"

class Square;

class GuiManager {

private:
    static GuiManager *instance_;
    Ui::RoadRace *ui;
    bool end;
    GuiManager(){}
 public:
    static GuiManager& instance();
    void setUi ( Ui::RoadRace *ui_ ) { ui = ui_; }
    Ui::RoadRace *getUi ( ) { return ui; }

    ~GuiManager() { delete instance_; }

    void init();
    void generateSquareGrid();
    void fillResourceList();
    QPixmap setmap(Square *sq, int size);
    void newDiff();
    void BuildStruct(Square *proc);

    //getterMethods
    bool getEndGame() { return end; }

    //setterMethods
    void setEndGame(bool b) { end = b; }

    //endgame
    void endGame(SquareLabel* x);

private slots:

    void on_helpBtn_pressed();

};


#endif // GUI_H
