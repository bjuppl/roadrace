#ifndef ROADRACE_H
#define ROADRACE_H

#include <QMainWindow>

namespace Ui {
class RoadRace;
}

class RoadRace : public QMainWindow
{
    Q_OBJECT

public:
    explicit RoadRace(QWidget *parent = 0);
    ~RoadRace();

private:
    Ui::RoadRace *ui;
};

#endif // ROADRACE_H
