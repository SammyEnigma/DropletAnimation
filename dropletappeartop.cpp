#include "dropletappeartop.h"

DropletAppearTop::DropletAppearTop(QWidget *parent, int left, int right, int top, int height, QColor color) : QWidget(parent),
    color(color), progress(0), step(APPEAR)
{
    setGeometry(left, top, right-left, height);
    drip_r = height/ 10+1;
    this->show();
}

void DropletAppearTop::play(int duration)
{
    appear(duration);
}

void DropletAppearTop::paintEvent(QPaintEvent *event)
{
    if (progress == 0)
        return ;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPoint left, right;

    if (step == APPEAR)
    {
        // 获取滴落的控制点位置
        left = QPoint(width()/2*progress/100-drip_r, 0);
        right = QPoint(width() - width()/2*progress/100+drip_r, 0);
    }
    else if (step == DISAPPEAR)
    {
        // 固定滴落的控制点位置为上阶段动画的结果
        left = QPoint(width()/2-drip_r, 0);
        right = QPoint(width()/2+drip_r, 0);
    }

    // 获取滴落的高度和中心点
    int h = height() * progress / 100;
    QPoint mid(width()/2, h);

    // 计算控制点
    QPoint ctrl_l1(width()/2-drip_r, 0);
    QPoint ctrl_l2(width()/2-drip_r, h);
    QPoint ctrl_r1(width()/2+drip_r, h);
    QPoint ctrl_r2(width()/2+drip_r, 0);

    // 计算路径
    QPainterPath path;
    path.moveTo( 0, 0);
    path.cubicTo(ctrl_l1, ctrl_l2, mid);
    path.cubicTo(ctrl_r1, ctrl_r2, QPoint(width(), 0));
    path.lineTo(left);

    // 绘制背景
    painter.fillPath(path, color);
}

void DropletAppearTop::appear(int duration)
{
    step = APPEAR;
    QPropertyAnimation* animation = new QPropertyAnimation(this, "progress");
    animation->setStartValue(0);
    animation->setEndValue(100);
    animation->setDuration(duration);
    connect(animation, &QPropertyAnimation::finished, this, [=]{
        animation->deleteLater();
        disappear(duration>>1);
    });
    animation->start();
}

void DropletAppearTop::disappear(int duration)
{
    step = DISAPPEAR;
    QPropertyAnimation* animation = new QPropertyAnimation(this, "progress");
    animation->setStartValue(progress);
    animation->setEndValue(0);
    animation->setDuration(duration);
    connect(animation, &QPropertyAnimation::finished, this, [=]{
        animation->deleteLater();
        this->deleteLater();
    });
    animation->start();
}

void DropletAppearTop::setProgress(int x)
{
    this->progress = x;
    update();
}
