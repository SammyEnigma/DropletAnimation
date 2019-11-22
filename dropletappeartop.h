#ifndef DROPLETAPPEARTOP_H
#define DROPLETAPPEARTOP_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QLine>

class DropletAppearTop : public QWidget
{
    Q_OBJECT
public:
    DropletAppearTop(QWidget *parent, QLine line, QColor color);

signals:

public slots:
};

#endif // DROPLETAPPEARTOP_H
