#ifndef DROPLETAPPEARANIMATION_H
#define DROPLETAPPEARANIMATION_H

#include <QObject>
#include <QLine>
#include <QRect>
#include <QColor>
#include <QPoint>
#include <QWidget>
#include <QPropertyAnimation>

class DropletAppearAnimation : public QObject
{
    Q_OBJECT
public:
    static DropletAppearAnimation* startAnimation(QWidget* parent, QColor color, QLine appear_line, QRect target_rect, int target_radius);

private:
    DropletAppearAnimation(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DROPLETAPPEARANIMATION_H
