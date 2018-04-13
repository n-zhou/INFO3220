#include "concretepoolfactory.h"

#include <QDebug>
#include <iostream>

ConcretePoolFactory::ConcretePoolFactory():AbstractPool()
{

}

//constructor takes
ConcretePoolFactory::ConcretePoolFactory(QJsonObject json):
    AbstractPool(),
    table(json["table"].toObject()),
    balls(json["balls"].toArray())
{

}

ConcretePoolFactory::~ConcretePoolFactory()
{

}

//returns a pointer to the table created from the config file
Table* ConcretePoolFactory::createTable()
{

    return new PoolTable(table["colour"].toString(),
            table["size"].toObject()["x"].toDouble(),
            table["size"].toObject()["y"].toDouble(),
            table["friction"].toDouble());
}

//returns a vector containing all the balls in the provided config file
std::vector<Ball*> ConcretePoolFactory::createBalls()
{
    std::vector<Ball*> ret;
    for(int i = 0; i < balls.size(); i++){
        QJsonObject ball = balls[i].toObject();
        QJsonObject position = ball["position"].toObject();
        QJsonObject velocity = ball["velocity"].toObject();
        ret.push_back(new PoolBall(ball["colour"].toString(), position["x"].toDouble(), position["y"].toDouble(), velocity["x"].toDouble(), velocity["y"].toDouble(),
                ball["mass"].toDouble(), ball["radius"].toDouble()));
    }
    return ret;
}
