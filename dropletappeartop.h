#ifndef DROPLETAPPEARTOP_H
#define DROPLETAPPEARTOP_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QLine>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QDebug>

class DropletAppearTop : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int progress WRITE setProgress)
public:
    DropletAppearTop(QWidget *parent, int left, int right, int top, int height, QColor color);

    void play(int duration = 300);

    enum Step {
        PREPARE = 0,
        APPEAR = 1,
        DISAPPEAR = 2
    };

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void appear(int duration);
    void disappear(int duration);

    void setProgress(int x);

signals:

public slots:

private:
    QColor color;
    int progress;
    Step step;
};

#endif // DROPLETAPPEARTOP_H
