#ifndef GUI_H
#define GUI_H

#include "ui_roadrace.h"
#include "roadrace.h"
#include "gamemodel.h"

#include "square.h"

class GuiManager {

private:
    static GuiManager *instance_;
    Ui::RoadRace *ui;

    GuiManager(){}
 public:
    static GuiManager& instance();
    void setUi ( Ui::RoadRace *ui_ ) { ui = ui_; }
    Ui::RoadRace *getUi ( ) { return ui; }

    ~GuiManager() { delete instance_; }

    void generateSquareGrid();
    void fillResourceList();
    QPixmap setmap(Square *sq, int size);
    void newDiff();

private slots:
    void on_helpBtn_clicked();
};


#endif // GUI_H
