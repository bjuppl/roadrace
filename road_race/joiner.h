#ifndef JOINER_H
#define JOINER_H

#include <QDialog>
#include <QTcpSocket>
namespace Ui {
class joiner;
}

class joiner : public QDialog
{
    Q_OBJECT

public:
    explicit joiner(QWidget *parent = 0);
    ~joiner();

private slots:
    void on_killBtn_clicked();
    void data_received();
    void on_joinBtn_clicked();

private:
    Ui::joiner *ui;
    QTcpSocket *socket;
};

#endif // JOINER_H
