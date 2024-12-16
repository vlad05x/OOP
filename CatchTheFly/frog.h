#ifndef FROG_H
#define FROG_H

#include <QLabel>
#include <QPoint>
#include <QTimer>

class Frog {
public:
    Frog(QLabel* frogLabel, int speed, const QPoint& startPos);
    void moveTowardsFly(const QPoint& flyPos);
    void changeSkin(const QString& newSkinPath);
    bool hasCaughtFly(const QRect& flyRect);

private:
    QLabel* frogLabel;
    int speed;
    QPoint position;
};

#endif // FROG_H
