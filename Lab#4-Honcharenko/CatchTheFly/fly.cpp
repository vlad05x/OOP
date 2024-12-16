#include "fly.h"
#include <QPixmap>
#include <cmath>

Fly::Fly(QLabel* flyLabel, int speed, const QString& skinPath)
    : flyLabel(flyLabel), speed(speed) {
    changeSkin(skinPath);
}

void Fly::changeSkin(const QString& newSkinPath) {
    QPixmap pixmap(newSkinPath);
    pixmap = pixmap.scaled(flyLabel->size(), Qt::KeepAspectRatio);
    flyLabel->setPixmap(pixmap);
}

void Fly::moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect) {
    QPoint flyPos = flyLabel->pos();

    int dx = flyPos.x() - cursorPos.x();
    int dy = flyPos.y() - cursorPos.y();

    int distance = static_cast<int>(std::sqrt(dx * dx + dy * dy));

    if (distance < 100) {
        dx = dx * speed / distance;
        dy = dy * speed / distance;
    } else {
        dx = 0;
        dy = 0;
    }

    int newX = std::clamp(flyPos.x() + dx, 0, windowRect.width() - flyLabel->width());
    int newY = std::clamp(flyPos.y() + dy, 0, windowRect.height() - flyLabel->height());

    flyLabel->move(newX, newY);
}

FlyLevel2::FlyLevel2(QLabel* flyLabel, int speed, const QRect& escapeWindow)
    : Fly(flyLabel, speed, "/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/fly2.png"), escapeWindow(escapeWindow) {}

void FlyLevel2::moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect) {
    Fly::moveAwayFromCursor(cursorPos, windowRect);

    QPoint flyPos = flyLabel->pos();
    int dx = escapeWindow.center().x() - flyPos.x();
    int dy = escapeWindow.center().y() - flyPos.y();

    if (std::abs(dx) < 50 && std::abs(dy) < 50) {
        flyLabel->move(flyPos.x() + (dx > 0 ? speed / 2 : -speed / 2),
                       flyPos.y() + (dy > 0 ? speed / 2 : -speed / 2));
    }
}

FlyLevel3::FlyLevel3(QLabel* flyLabel, int speed, const QRect& escapeWindow)
    : FlyLevel2(flyLabel, speed, escapeWindow) {
    changeSkin("/home/vlad05x/DevZone/University/oop/OOP/Lab#4-Honcharenko/CatchTheFly/fly3.png");
}

void FlyLevel3::moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect) {
    FlyLevel2::moveAwayFromCursor(cursorPos, windowRect);
    flyLabel->move(flyLabel->x() + (rand() % 5 - 2), flyLabel->y() + (rand() % 5 - 2));
}
