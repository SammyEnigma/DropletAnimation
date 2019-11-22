#include "dropletappearanimation.h"

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QLine appear_line, int drip_height, QRect target_rect, int target_radius)
{

}

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QWidget *target_widget, int top_margin, int drip_height, int target_radius)
{
    QRect target_rect = target_widget->geometry();
    int x1, x2;
    if (target_rect.width() > drip_height * TOP_LINE_MAX_PROG)
    {
        x1 = target_rect.center().x() - drip_height * TOP_LINE_MAX_PROG / 2;
        x2 = target_rect.center().x() + drip_height * TOP_LINE_MAX_PROG / 2;
    }
    else
    {
        x1 = target_rect.left();
        x2 = target_rect.right();
    }
    DropletAppearTop* top = new DropletAppearTop(parent, x1, x2, top_margin, drip_height, color);


    top->play(300);
}

DropletAppearAnimation::DropletAppearAnimation(QObject *parent) : QObject(parent)
{

}
