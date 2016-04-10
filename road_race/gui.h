#ifndef GUI_H
#define GUI_H

#include <QObject>
#include "ui_roadrace.h"
#include "roadrace.h"
#include "gamemodel.h"
#include "squarelabel.h"

class Square;
class RoadRace;

class GuiManager:QObject {
Q_OBJECT
private:
    static GuiManager *instance_;
    Ui::RoadRace *ui;
    RoadRace *window;
    bool end;
    GuiManager(){}
 public:
    static GuiManager& instance();
    void setUi ( Ui::RoadRace *ui_ ) { ui = ui_; }
    void setWindow ( RoadRace *win_ ) { window = win_; }
    void setTimeBox( size_t time ) { ui->lblTime->setText(QString::fromStdString(std::to_string(time))); }
    Ui::RoadRace *getUi ( ) { return ui; }
    RoadRace *getWindow() { return window; }

    ~GuiManager() { delete instance_; }

    void init();
    void generateSquareGrid();
    void fillResourceList();
    QPixmap setmap(Square *sq, QSize size);
    void newDiff();
    void BuildStruct(Square *proc);

    //getterMethods
    bool getEndGame() { return end; }

    //setterMethods
    void setEndGame(bool b) { end = b; }

    //endgame
    void endGame(SquareLabel* x);

private slots:

    //void on_helpBtn_pressed();



    void on_btnSendToServer_clicked();
    void on_btnConnect_clicked();
    void on_testBtn_clicked();

};


#endif // GUI_H
