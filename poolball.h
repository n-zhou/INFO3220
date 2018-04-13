#ifndef POOLBALL_H
#define POOLBALL_H

#include "ball.h"

class PoolBall : public Ball
{
public:
    PoolBall();

    PoolBall(QString colour,
             double xCoordinate,
             double yCoordinate,
             double xVelocity,
             double yVelocity,
             double mass,
             double radius);

    ~PoolBall();

    /**
     * @brief render is implemented in order to inherit the
     * Ball class.
     * @param painter
     * @param time
     */
    void render(QPainter &painter, unsigned int time);

private:
};

#endif // POOLBALL_H
