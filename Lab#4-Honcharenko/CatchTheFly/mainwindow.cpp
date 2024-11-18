#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap flyPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/fly.png");
    flyPixmap = flyPixmap.scaled(80, 80, Qt::KeepAspectRatio);
    ui->l_fly->setPixmap(flyPixmap);

    QPixmap trapPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/trap.png");
    trapPixmap = trapPixmap.scaled(100, 100, Qt::KeepAspectRatio);
    ui->l_trap->setPixmap(trapPixmap);

    QPixmap trapCactusPixmap("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/cactus.png");
    trapCactusPixmap = trapCactusPixmap.scaled(80, 80, Qt::KeepAspectRatio);

    cactus = {ui->l_cactus, ui->l_cactus_2, ui->l_cactus_3, ui->l_cactus_4, ui->l_cactus_5, ui->l_cactus_6, ui->l_cactus_7};
    for (QLabel* cact : cactus) {
        cact->setPixmap(trapCactusPixmap);
    }

    resetGame();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resetGame() {
    ui->l_fly->move(50, 400);
}

bool MainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        moveFly(mouseEvent->pos());
    }
    return QMainWindow::event(event);
}

void MainWindow::moveFly(QPoint cursorPos) {
    QPoint flyPos = ui->l_fly->pos();
    int dx = flyPos.x() - cursorPos.x();
    int dy = flyPos.y() - cursorPos.y();

    if (abs(dx) < 20 && abs(dy) < 100) {
        int newX = flyPos.x() + (dx > 0 ? 10 : -10);
        int newY = flyPos.y() + (dy > 0 ? 10 : -10);

        QRect windowRect = this->geometry();
        QRect flyRect = ui->l_fly->geometry();

        if (newX < 0) newX = 0;

        if (newX + flyRect.width() > windowRect.width())
            newX = windowRect.width() - flyRect.width();

        if (newY < 0) newY = 0;
        if (newY + flyRect.height() > windowRect.height())
            newY = windowRect.height() - flyRect.height();

        ui->l_fly->move(newX, newY);
    }


    if (isFlyInTrap()) {
        QMessageBox::information(this, "You are win!!!", "Fly in trap!!!");
        resetGame();
    } else if (isFlyInCactus()) {
        QMessageBox::critical(this, "You lose!", "Fly hit a cactus!");
        resetGame();
    }
}

bool MainWindow::isFlyInTrap() {
    QRect flyRect = ui->l_fly->geometry();
    QRect trapRect = ui->l_trap->geometry();
    return trapRect.contains(flyRect.center());
}

bool MainWindow::isFlyInCactus() {
    QRect flyRect = ui->l_fly->geometry();
    for (QLabel* cactusLabel : cactus) {
        QRect cactusRect = cactusLabel->geometry();
        if (cactusRect.contains(flyRect.center())) {
            return true;
        }
    }
    return false;
}
