#ifndef ABSTRACTPOOL_H
#define ABSTRACTPOOL_H

#include <vector>
#include "table.h"
#include "ball.h"

class AbstractPool
{
public:

    AbstractPool(){}
    virtual ~AbstractPool(){}

    virtual Table* createTable() = 0;
    virtual std::vector<Ball*> createBalls() = 0;
};

#endif // ABSTRACTPOOL_H
