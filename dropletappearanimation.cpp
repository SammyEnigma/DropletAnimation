#include "dropletappearanimation.h"

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QLine appear_line, QRect target_rect, int target_radius)
{

}

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QWidget *target_widget, int top_margin, int target_radius)
{
    QLine line;
    DropletAppearTop* top = new DropletAppearTop(parent, line, color);

}

DropletAppearAnimation::DropletAppearAnimation(QObject *parent) : QObject(parent)
{

}
