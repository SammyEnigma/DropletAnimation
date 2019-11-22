#ifndef DROPLETAPPEARANIMATION_H
#define DROPLETAPPEARANIMATION_H

#include <QObject>
#include <QLine>
#include <QRect>
#include <QColor>
#include <QPoint>
#include <QWidget>
#include <QPropertyAnimation>
#include "dropletappeartop.h"
#include "dropletappeardrip.h"
#include "dropletappearcollide.h"

/**
 * 水滴出现动画工具类
 * 阶段一：顶部水滴即将滴落
 * 阶段二：水滴动态滴落
 * 阶段三：水滴与地面碰撞成目标控件
 */

class DropletAppearAnimation : public QObject
{
    Q_OBJECT
public:
    static DropletAppearAnimation* startAnimation(QWidget* parent, QColor color, QLine appear_line, int drip_height, QRect target_rect, int target_radius = 0);
    static DropletAppearAnimation* startAnimation(QWidget* parent, QColor color, QWidget* target_widget, int top_margin = 0, int drip_height = 32, int target_radius = 0);

private:
    DropletAppearAnimation(QObject *parent = nullptr);

signals:
    void finished();

public slots:
};

#endif // DROPLETAPPEARANIMATION_H
