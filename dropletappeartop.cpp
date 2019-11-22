#include "dropletappeartop.h"

DropletAppearTop::DropletAppearTop(QWidget *parent, int left, int right, int top, int height, QColor color) : QWidget(parent),
    color(color), progress(0), step(APPEAR)
{
    setGeometry(left, top, right-left, height);
    this->show();
    qDebug() << "顶部" << geometry();
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

    // 出现动画：中间逐渐下移，两边逐渐收缩，显示弧线
    if (step == APPEAR)
    {
        // 获取滴落的宽度
        QPoint left(width()/2*progress/100, 0),
               right(width() - width()/2*progress/100, 0);

        // 获取滴落的高度
        int h = height() * progress / 100;
        QPoint mid(width()/2, h);

        // 计算控制点
        QPoint ctrl_l1(0, 0);
        QPoint ctrl_l2((left.x() + width()/2)/2, 0);
        QPoint ctrl_r1((right.x()+width()/2)/2, 0);
        QPoint ctrl_r2(width(), 0);

        // 计算路径
        QPainterPath path;
        path.moveTo(left);
        path.cubicTo(ctrl_l1, ctrl_l2, mid);
        path.cubicTo(ctrl_r1, ctrl_r2, right);
        path.moveTo(left);

        // 绘制背景
        painter.fillPath(path, color);

        painter.setPen(Qt::red);
        painter.drawEllipse(left.x()-2, left.y()-2, 4, 4);
        painter.drawEllipse(right.x()-2, right.y()-2, 4, 4);
        painter.setPen(Qt::green);
        painter.drawEllipse(ctrl_l1.x()-2, ctrl_l1.y()-2, 4, 4);
        painter.drawEllipse(ctrl_l2.x()-2, ctrl_l2.y()-2, 4, 4);

    }
    // 消失动画：两边逐渐收缩至中间，消失
    else if (step == DISAPPEAR)
    {
        // 获取滴落的宽度
        QPoint left(width()/2-1, 0),
               right(width()/2+1, 0);

        // 获取滴落的高度
        int h = height() * progress / 100;
        QPoint mid(width()/2, h);

        // 计算控制点
        QPoint ctrl_l1(0, 0);
        QPoint ctrl_l2((left.x() + width()/2)/2, 0);
        QPoint ctrl_r1((right.x()+width()/2)/2, 0);
        QPoint ctrl_r2(width(), 0);

        // 计算路径
        QPainterPath path;
        path.moveTo(left);
        path.cubicTo(ctrl_l1, ctrl_l2, mid);
        path.cubicTo(ctrl_r1, ctrl_r2, right);
        path.moveTo(left);

        // 绘制背景
        painter.fillPath(path, color);

        painter.setPen(Qt::red);
        painter.drawEllipse(left.x()-2, left.y()-2, 4, 4);
        painter.drawEllipse(right.x()-2, right.y()-2, 4, 4);
        painter.setPen(Qt::green);
        painter.drawEllipse(ctrl_l1.x()-2, ctrl_l1.y()-2, 4, 4);
        painter.drawEllipse(ctrl_l2.x()-2, ctrl_l2.y()-2, 4, 4);
    }
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
