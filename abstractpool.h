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

    /**
     * @brief createTable
     * @return returns a pointer to the table which the caller must free.
     */
    virtual Table* createTable() = 0;

    /**
     * @brief createBalls
     * @return returns a vector containing pointer to balls.
     * The caller is responsible for freeing the memory from the pointer that the
     * vector holds.
     */
    virtual std::vector<Ball*> createBalls() = 0;
};

#endif // ABSTRACTPOOL_H
