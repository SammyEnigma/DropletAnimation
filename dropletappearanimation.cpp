#include "dropletappearanimation.h"

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QLine appear_line, int drip_height, QRect target_rect, int target_radius)
{

}

DropletAppearAnimation *DropletAppearAnimation::startAnimation(QWidget *parent, QColor color, QWidget *target_widget, int top_margin, int drip_height, int target_radius)
{
    qDebug() << "开始动画";
    QRect target_rect = target_widget->geometry();
    DropletAppearTop* top = new DropletAppearTop(parent, target_rect.left(), target_rect.right(), top_margin, drip_height, color);


    top->play(300);
}

DropletAppearAnimation::DropletAppearAnimation(QObject *parent) : QObject(parent)
{

}
