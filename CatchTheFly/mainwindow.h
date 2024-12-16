#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QVector>
#include <QTimer>
#include "fly.h"
#include "frog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool event(QEvent* event) override;

private:
    Ui::MainWindow *ui;
    QTimer* flyTimer;
    Fly* currentFly;
    Frog* currentFrog;
    QVector<Fly*> flies;

    int currentLevel;

    int fliesEatenByFrog;
    int deathCounter;

    QLabel* escapeWindow;
    QLabel* fliesEatenLabel;
    QLabel* deathCounterLabel;

    void initGame();
    void startLevel(int level);
    void resetGame();
    void updateFliesEatenLabel();
    void updateDeathCounterLabel();
    bool isFlyInTrap();
    bool isFlyInWindow();

private slots:
    void moveFlyTowardsWindow();
};

#endif // MAINWINDOW_H
