#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void getDigit();
    void setOper();
    void getResult();
    void C();
    void CE();

private:
    Ui::MainWindow *ui;
    QVector<QPushButton> btns;
    QString operation;
    QString prevNum;
};
#endif // MAINWINDOW_H
