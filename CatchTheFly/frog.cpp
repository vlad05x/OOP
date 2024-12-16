#include "frog.h"
#include <QPixmap>
#include <cmath>

Frog::Frog(QLabel* frogLabel, int speed, const QPoint& startPos)
    : frogLabel(frogLabel), speed(speed), position(startPos) {
    changeSkin("/home/vlad05x/DevZone/University/oop/OOP/CatchTheFly/frog.png");
}

void Frog::moveTowardsFly(const QPoint& flyPos) {
    int dx = flyPos.x() - position.x();
    int dy = flyPos.y() - position.y();
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > 5) {
        position.setX(position.x() + static_cast<int>(speed * dx / distance));
        position.setY(position.y() + static_cast<int>(speed * dy / distance));
        frogLabel->move(position);
    }
}


void Frog::changeSkin(const QString& newSkinPath) {
    QPixmap pixmap(newSkinPath);
    pixmap = pixmap.scaled(frogLabel->size(), Qt::KeepAspectRatio);
    frogLabel->setPixmap(pixmap);
}

bool Frog::hasCaughtFly(const QRect& flyRect) {
    return frogLabel->geometry().intersects(flyRect);
}
