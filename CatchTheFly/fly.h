#ifndef FLY_H
#define FLY_H

#include <QLabel>
#include <QRect>
#include <QPoint>

class Fly {
public:
    Fly(QLabel* flyLabel, int speed, const QString& skinPath);
    virtual ~Fly() = default;

    virtual void moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect);
    void changeSkin(const QString& newSkinPath);

    QLabel* getFlyLabel() const { return flyLabel; }
     int getSpeed() const { return speed; }

protected:
    QLabel* flyLabel;
    int speed;
};

class FlyLevel2 : public Fly {
public:
    FlyLevel2(QLabel* flyLabel, int speed, const QRect& escapeWindow);
    void moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect) override;

private:
    QRect escapeWindow;
};

class FlyLevel3 : public FlyLevel2 {
public:
    FlyLevel3(QLabel* flyLabel, int speed, const QRect& escapeWindow);
    void moveAwayFromCursor(const QPoint& cursorPos, const QRect& windowRect) override;
};

#endif // FLY_H
