#ifndef BALL_H
#define BALL_H

#include <QString>
#include <QPainter>
#include <QVector2D>

class Ball
{
public:
    Ball(){}

    /**
     * @brief Ball
     * @param colour
     * @param xCoordinate
     * @param yCoordinate
     * @param xVelocity
     * @param yVelocity
     * @param mass
     * @param radius
     */
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

    /**
     * @brief ~Ball
     * Ball should have no memory to cleanup so the destructor should be empty.
     */
    virtual ~Ball(){}

    /**
     * @brief render
     * All subclasses must implement this method in order to inheirit from
     * the ball class.
     * @param painter is used to draw the ball
     * @param time
     *
     */
    virtual void render(QPainter &painter, unsigned int time) = 0;

    /**
     * @brief getColour
     * @return a QString representation of ball colour.
     */
    virtual QString getColour(){return m_colour;}

    /**
     * @brief getPosition
     * @return a QVector2D version of the ball position
     */
    virtual QVector2D& getPosition(){return m_position;}

    /**
     * @brief getVelocity
     * @return a QVector2D representation of the ball velocity.
     */
    virtual QVector2D& getVelocity(){return m_velocity;}

    /**
     * @brief mass
     * @return the mass of the ball.
     */
    virtual double mass(){return m_mass;}

    /**
     * @brief radius
     * @return the radius of the ball.
     */
    virtual double radius(){return m_radius;}

protected:
    QString m_colour;
    QVector2D m_position;
    QVector2D m_velocity;
    double m_mass;
    double m_radius;
};

#endif // BALL_H
