#ifndef CHEATER_H
#define CHEATER_H

#include <QDialog>

namespace Ui {
class cheater;
}

class cheater : public QDialog
{
    Q_OBJECT

public:
    explicit cheater(QWidget *parent = 0);
    ~cheater();

private slots:
    void on_canBtn_clicked();

    void on_yesBtn_clicked();



    void on_RndBox_toggled(bool checked);

private:
    Ui::cheater *ui;
};

#endif // CHEATER_H
