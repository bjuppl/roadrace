#ifndef GUI_H
#define GUI_H

#include "roadrace.h"
#include "gamemodel.h"

class GuiManager {

private:
    static GuiManager *instance_;
    Ui::RoadRace *ui;

    GuiManager(){}
 public:
    static GuiManager& instance();
    void setUi ( Ui::RoadRace *ui_ ) { ui = ui_; }

    void generateSquareGrid();
};


#endif // GUI_H
