#include "my_widget.h"

#include <QPainter>

MyWidget::MyWidget(QWidget *parent) //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPen pen;
    pen.setWidth(4);
    painter.setPen(pen);
    int xS = (rect().width() / 2.0);
    int yS = (rect().height() / 2.0);
    painter.drawLine(xS - 10, yS, xS + 10, yS);
    painter.drawLine(xS, yS - 10, xS, yS + 10);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);

    QRadialGradient radialGrad(QPointF(0, 192), 32);
    radialGrad.setColorAt(0, Qt::magenta);
    radialGrad.setColorAt(1, Qt::lightGray);
    QRect rect_radial(-32, 160, 64, 64);

    // auto side = std::min(rect().width(), rect().height());
    // painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.fillRect(rect_radial, radialGrad);
        }
        painter.rotate(360.0 / num_disks);
    }
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    // clicked += 1;
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
