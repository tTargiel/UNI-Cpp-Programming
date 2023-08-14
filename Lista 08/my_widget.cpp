#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <string>
#include <vector>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    setFocus();
}

void MyWidget::paintEvent([[maybe_unused]] QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));
    auto r = this->rect();
    painter.drawRect(r);

    if (circles.size() > 0)
    {
        painter.setBrush(QBrush(QColor(circles[0].color)));
        for (const auto &circ : circles)
        {
            QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
            painter.drawEllipse(point, circ.radius, circ.radius);
        }
    }
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    auto pos = event->localPos();
    auto rec = rect();
    Circle c;
    c.radius = DEFAULT_RADIUS;
    c.center.setX(pos.x() / rec.width());
    c.center.setY(pos.y() / rec.height());
    circles.push_back(c);
    repaint();
}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    if (circles.size() > 0 && event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Z)
    {
        circles.pop_back();
        repaint();
    }
}

void MyWidget::wheelEvent(QWheelEvent *event)
{
    QString myColors[] = {"red", "green", "blue", "orange", "mediumaquamarine", "purple", "yellow", "mediumturquoise", "violet"};
    static int n = 0;
    if (event->angleDelta().y() > 0)
    {
        n++;
        if (n > 8)
        {
            n = 0;
        }
        circles[0].color = myColors[n];
        repaint();
    }
    else if (event->angleDelta().y() < 0)
    {
        n--;
        if (n < 0)
        {
            n = 8;
        }
        circles[0].color = myColors[n];
        repaint();
    }
}
