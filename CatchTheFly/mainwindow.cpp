#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QVector>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentFly(nullptr), currentFrog(nullptr),
    currentLevel(1), fliesEatenByFrog(0), deathCounter(0), escapeWindow(nullptr) {
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow {"
                        "background-image: url(/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/room.jpg);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-size: contain; }");

    QPixmap trapPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/trap.png");
    ui->l_trap->setPixmap(trapPixmap.scaled(100, 100, Qt::KeepAspectRatio));

    flyTimer = new QTimer(this);
    connect(flyTimer, &QTimer::timeout, this, &MainWindow::moveFlyTowardsWindow);

    fliesEatenLabel = new QLabel(this);
    fliesEatenLabel->setGeometry(10, 10, 200, 30);
    fliesEatenLabel->setStyleSheet("color: red; font-size: 15px;");
    updateFliesEatenLabel();

    deathCounterLabel = new QLabel(this);
    deathCounterLabel->setGeometry(10, 50, 200, 30);
    deathCounterLabel->setStyleSheet("color: red; font-size: 15px;");
    updateDeathCounterLabel();

    initGame();
}

MainWindow::~MainWindow() {
    delete currentFly;
    delete currentFrog;
    delete flyTimer;
    delete fliesEatenLabel;
    delete deathCounterLabel;
    delete ui;
}

void MainWindow::initGame() {
    fliesEatenByFrog = 0;
    deathCounter = 0;
    currentLevel = 1
        ;
    startLevel(currentLevel);
}

void MainWindow::startLevel(int level) {
    delete currentFrog;

    if (level == 1) {
        if (!escapeWindow) {
            escapeWindow = new QLabel(this);
            escapeWindow->setGeometry(300, 150, 150, 150);
            QPixmap windowPixmap("/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/window.png");
            windowPixmap = windowPixmap.scaled(escapeWindow->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            escapeWindow->setPixmap(windowPixmap);
            escapeWindow->show();
        }

        currentFly = new Fly(ui->l_fly, 15, "/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/fly.png");
        flies.clear();
        flies.append(currentFly);
    } else if (level == 2) {
        if (!escapeWindow) {
            escapeWindow = new QLabel(this);
            escapeWindow->setGeometry(300, 150, 150, 150);
            QPixmap windowPixmap("/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/window.png");
            windowPixmap = windowPixmap.scaled(escapeWindow->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            escapeWindow->setPixmap(windowPixmap);
            escapeWindow->show();
        }

        Fly* fly1 = new Fly(ui->l_fly, 10, "/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/fly.png");
        Fly* fly2 = new FlyLevel2(ui->l_fly2, 10, escapeWindow->geometry());
        flies.clear();
        flies.append(fly1);
        flies.append(fly2);

        flyTimer->start(50);
    } else if (level == 3) {
        escapeWindow = nullptr;
        currentFrog = new Frog(ui->l_frog, 4, QPoint(100, 100));
        currentFly = new FlyLevel3(ui->l_fly, 35, QRect());
        flies.clear();
        flies.append(currentFly);

        flyTimer->start(30);
    } else {
        QMessageBox::information(this, "Congratulations!", "You have passed all levels!");
        initGame();
        return;
    }

    for (Fly* fly : flies) {
        if (fly->getFlyLabel()) {
            fly->getFlyLabel()->move(50, 400);
        }
    }
}

void MainWindow::resetGame() {
    flyTimer->stop();
    currentLevel = 1;
    startLevel(currentLevel);
}

void MainWindow::moveFlyTowardsWindow() {
    for (Fly* fly : flies) {
        if (!fly || !fly->getFlyLabel()) continue;

        QLabel* flyLabel = fly->getFlyLabel();
        QPoint flyPos = flyLabel->pos();

        if (currentFrog) {
            currentFrog->moveTowardsFly(flyPos);

            if (currentFrog->hasCaughtFly(flyLabel->geometry())) {
                flies.removeOne(fly);
                delete fly;
                fliesEatenByFrog++;

                if (currentLevel == 3) {
                    QMessageBox::information(this, "Game Over", "Congratulations! You've finished the game!");
                    resetGame();
                    return;
                }

                if (flies.isEmpty()) {
                    flyTimer->stop();
                    QMessageBox::information(this, "Congratulations!", "All flies are in the trap!");
                    startLevel(++currentLevel);
                }
            }
        }

        if (escapeWindow) {
            QPoint windowCenter = escapeWindow->geometry().center();
            int dx = windowCenter.x() - flyPos.x();
            int dy = windowCenter.y() - flyPos.y();
            double distance = sqrt(dx * dx + dy * dy);

            int step = static_cast<int>(fly->getSpeed() * 0.5);

            if (distance > step) {
                flyPos.setX(flyPos.x() + static_cast<int>(step * dx / distance));
                flyPos.setY(flyPos.y() + static_cast<int>(step * dy / distance));
                flyLabel->move(flyPos);
            }
        }

        if (escapeWindow && escapeWindow->geometry().contains(flyLabel->geometry().center())) {
            deathCounter++;
            updateDeathCounterLabel();

            flyTimer->stop();
            QMessageBox::critical(this, "You lose!", "A fly has escaped!");
            startLevel(3);
            return;
        }

        if (ui->l_trap->geometry().contains(flyLabel->geometry().center())) {
            flies.removeOne(fly);
            delete fly;
            if (flies.isEmpty()) {
                flyTimer->stop();
                QMessageBox::information(this, "Congratulations!", "Fly is caught");
                startLevel(++currentLevel);
            }
            return;
        }
    }
}




bool MainWindow::event(QEvent* event) {
    if (event->type() == QEvent::MouseMove) {
        auto* mouseEvent = static_cast<QMouseEvent*>(event);
        if (currentFly) currentFly->moveAwayFromCursor(mouseEvent->pos(), this->geometry());

        if (isFlyInTrap()) {
            deathCounter++;
            updateDeathCounterLabel();

            flyTimer->stop();
            QMessageBox::information(this, "Congratulations!", "The fly is in the trap!");
            startLevel(++currentLevel);
        }
    }
    return QMainWindow::event(event);
}

bool MainWindow::isFlyInTrap() {
    if (currentLevel == 3) return false;
    return ui->l_trap->geometry().contains(ui->l_fly->geometry().center());
}

bool MainWindow::isFlyInWindow() {
    if (currentLevel == 3) return false;
    if (!escapeWindow) return false;
    return escapeWindow->geometry().contains(ui->l_fly->geometry().center());
}

void MainWindow::updateFliesEatenLabel() {
    fliesEatenLabel->setText(QString("Flies eaten by frog: %1").arg(fliesEatenByFrog));
}

void MainWindow::updateDeathCounterLabel() {
    deathCounterLabel->setText(QString("Deaths: %1").arg(deathCounter));
}
