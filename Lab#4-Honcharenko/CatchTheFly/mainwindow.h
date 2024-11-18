#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>


#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent *event) override;

private:
    Ui::MainWindow *ui;

    QList<QLabel*> cactus;

    void moveFly(QPoint cursorPos);
    void resetGame();
    bool isFlyInTrap();

    bool isFlyInCactus();
};
#endif // MAINWINDOW_H
