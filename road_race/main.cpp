#include "roadrace.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // a.setStyle("gtk");
    RoadRace w;


    w.show();

    return a.exec();
}
