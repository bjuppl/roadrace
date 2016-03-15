#ifndef TITLE_H
#define TITLE_H

#include <QDialog>
#include "roadrace.h"
namespace Ui {
class title;
}

class title : public QDialog
{
    Q_OBJECT

public:
    explicit title(QWidget *parent = 0);
    ~title();
     void setFirst(bool f){first = f;}
     bool getFirst(){return first;}
private slots:
    void on_titleButton_2_clicked();

private:
    Ui::title *ui;
    bool first = true;
};

#endif // TITLE_H
