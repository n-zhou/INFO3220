#ifndef CONCRETEPOOLFACTORY_H
#define CONCRETEPOOLFACTORY_H

#include <QJsonObject>
#include <QJsonArray>
#include <vector>
#include "abstractpool.h"
#include "poolball.h"
#include "pooltable.h"
#include "ball.h"
#include "poolball.h"

class ConcretePoolFactory : public AbstractPool
{
public:
    ConcretePoolFactory();

    /**
    * takes in the json object of the whole json file
    * it must initialize the member variables table and balls accordingly
    */
    ConcretePoolFactory(QJsonObject json);

    ~ConcretePoolFactory();

    /**
     * @brief createTable implements a virtual method in
     * AbstractPool
     * @return
     */
    Table* createTable();

    /**
     * @brief createBalls implements a virtual method in
     * AbstractPool
     * @return
     */
    std::vector<Ball*> createBalls();

private:
    QJsonObject table;
    QJsonArray balls;
};

#endif // CONCRETEPOOLFACTORY_H
