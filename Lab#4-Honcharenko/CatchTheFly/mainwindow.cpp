#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QVector>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentFly(nullptr), currentLevel(1), escapeWindow(nullptr) {
    ui->setupUi(this);

    QPixmap trapPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/trap.png");
    ui->l_trap->setPixmap(trapPixmap.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap cactusPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/cactus.png");
    cactusLabels = {ui->l_cactus, ui->l_cactus_2, ui->l_cactus_3, ui->l_cactus_4, ui->l_cactus_5, ui->l_cactus_6, ui->l_cactus_7};
    for (auto cactus : cactusLabels) {
        cactus->setPixmap(cactusPixmap.scaled(80, 80, Qt::KeepAspectRatio));
    }

    flyTimer = new QTimer(this);
    connect(flyTimer, &QTimer::timeout, this, &MainWindow::moveFlyTowardsWindow);

    initGame();
}

MainWindow::~MainWindow() {
    delete currentFly;
    delete flyTimer;
    delete ui;
}

void MainWindow::initGame() {
    currentLevel = 3;
    startLevel(currentLevel);
}

void MainWindow::startLevel(int level) {
    delete currentFly;
    delete escapeWindow;

    if (level == 1) {
        currentFly = new Fly(ui->l_fly, 15, "/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/fly.png");
    } else if (level == 2) {
        if (!escapeWindow) {
            escapeWindow = new QLabel(this);
            escapeWindow->setGeometry(620, 450, 100, 100);
            QPixmap windowPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/window.png");
            windowPixmap = windowPixmap.scaled(escapeWindow->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            escapeWindow->setPixmap(windowPixmap);
            escapeWindow->show();
        }
        currentFly = new FlyLevel2(ui->l_fly, 25, escapeWindow->geometry());
        flyTimer->start(50);
    } else if (level == 3) {
        if (!escapeWindow) {
            escapeWindow = new QLabel(this);
            escapeWindow->setGeometry(620, 450, 100, 100);
            QPixmap windowPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/window.png");
            escapeWindow->setPixmap(windowPixmap.scaled(escapeWindow->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            escapeWindow->show();
        }
        currentFly = new FlyLevel3(ui->l_fly, 35, escapeWindow->geometry());
        currentFly->changeSkin("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/fly3.png");
        flyTimer->start(30);
    } else {
        QMessageBox::information(this, "Congratulations!", "You have passed all levels!");
        initGame();
        return;
    }

    ui->l_fly->move(50, 400);
}

void MainWindow::resetGame() {
    flyTimer->stop();
    currentLevel = 1;
    startLevel(currentLevel);
}

void MainWindow::moveFlyTowardsWindow() {
    if (!escapeWindow) return;

    QPoint flyPos = ui->l_fly->pos();
    QPoint windowCenter = escapeWindow->geometry().center();

    int dx = windowCenter.x() - flyPos.x();
    int dy = windowCenter.y() - flyPos.y();
    double distance = sqrt(dx * dx + dy * dy);

    int step = 5;
    if (distance > step) {
        flyPos.setX(flyPos.x() + static_cast<int>(step * dx / distance));
        flyPos.setY(flyPos.y() + static_cast<int>(step * dy / distance));
        ui->l_fly->move(flyPos);
    }

    if (isFlyInWindow()) {
        flyTimer->stop();
        QMessageBox::critical(this, "You lose!", "The fly has escaped!");
        resetGame();
    }
}

bool MainWindow::event(QEvent* event) {
    if (event->type() == QEvent::MouseMove) {
        auto* mouseEvent = static_cast<QMouseEvent*>(event);
        currentFly->moveAwayFromCursor(mouseEvent->pos(), this->geometry());

        if (isFlyInTrap()) {
            flyTimer->stop();
            QMessageBox::information(this, "Congratulations!", "The fly is in the trap!");
            startLevel(++currentLevel);
        } else if (isFlyInCactus()) {
            flyTimer->stop();
            QMessageBox::critical(this, "You lose!", "The fly hit a cactus!");
            resetGame();
        }
    }
    return QMainWindow::event(event);
}

bool MainWindow::isFlyInTrap() {
    return ui->l_trap->geometry().contains(ui->l_fly->geometry().center());
}

bool MainWindow::isFlyInCactus() {
    for (auto cactus : cactusLabels) {
        if (cactus->geometry().contains(ui->l_fly->geometry().center())) {
            return true;
        }
    }
    return false;
}

bool MainWindow::isFlyInWindow() {
    if (!escapeWindow) return false;
    return escapeWindow->geometry().contains(ui->l_fly->geometry().center());
}
