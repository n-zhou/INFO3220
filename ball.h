#ifndef BALL_H
#define BALL_H

#include <QString>
#include <QPainter>
#include <QVector2D>

class Ball
{
public:
    Ball(){}

    Ball(QString colour,
         double xCoordinate,
         double yCoordinate,
         double xVelocity,
         double yVelocity,
         double mass,
         double radius):
        m_colour(colour),
        m_position(QVector2D(xCoordinate, yCoordinate)),
        m_velocity(QVector2D(xVelocity, yVelocity)),
        m_mass(mass),
        m_radius(radius){}

    virtual ~Ball(){}

    virtual void render(QPainter &painter, unsigned int time) = 0;

    virtual QString getColour(){return m_colour;}
    virtual QVector2D& getPosition(){return m_position;}
    virtual QVector2D& getVelocity(){return m_velocity;}
    virtual double mass(){return m_mass;}
    virtual double radius(){return m_radius;}

protected:
    QString m_colour;
    QVector2D m_position;
    QVector2D m_velocity;
    double m_mass;
    double m_radius;
};

#endif // BALL_H
