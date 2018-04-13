#include "poolball.h"
#include <QDebug>

PoolBall::PoolBall():Ball(){}

PoolBall::PoolBall(QString colour,
                   double xCoordinate,
                   double yCoordinate,
                   double xVelocity,
                   double yVelocity,
                   double mass,
                   double radius):
    Ball(colour, xCoordinate, yCoordinate, xVelocity, yVelocity, mass, radius)
{

}


PoolBall::~PoolBall(){}

void PoolBall::render(QPainter &painter, unsigned int time)
{
    painter.setPen(Qt::black);
    //brush set to the colour of the ball
    painter.setBrush(QBrush(m_colour.toStdString().c_str()));
    //painter draws the ellipse
    painter.drawEllipse(m_position.toPointF(),
            m_radius,
            m_radius);
}

