#include "roadrace.h"
#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // a.setStyle("gtk");
    RoadRace w;
    GuiManager::instance().setWindow(&w);

    w.show();

    return a.exec();
}
