#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <cmath>
#include <QDebug>

#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    init();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(nextAnim()));
    timer->start(32);
    timer2->start(32);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    QFile file("config.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = d.object();
    AbstractPool *factory = new ConcretePoolFactory(json);
    m_table = factory->createTable();
    this->resize(m_table->getWidth(), m_table->getHeight());
    this->setStyleSheet((std::string("background-color: ") + m_table->getColour().toStdString()).c_str());
    m_balls = factory->createBalls();
    delete factory;
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i = 0; i < m_balls.size(); i++){
        m_balls.at(i)->render(painter, 0);
    }
}

void Dialog::nextAnim()
{
/*
    for(int i = 0; i < i < m_balls.size(); i++){
        //for(int j = i+1; j < m_balls.size(); j++){
           // handleBallCollision(m_balls.at(i), m_balls.at(j));
        //}
    }
*/
    //check collisions with wall
    for(int i = 0; i < m_balls.size(); i++){
        Ball *b = m_balls.at(i);
        for(int j = 0; j < m_balls.size(); j++){
            if(i == j)
                continue;
            Ball *b2 = m_balls.at(j);
            if(ballCollision(b, b2)){
                handleBallCollision(b, b2);
            }
        }
        if(isTopCollision(b) || isBottomCollision(b)){
            b->getVelocity().setY(-b->getVelocity().y());
        }
        if(isLeftCollision(b) || isRightCollision(b)){
            b->getVelocity().setX(-b->getVelocity().x());
        }
        b->getPosition().setX(b->getPosition().x() + (b->getVelocity().x()));
        b->getPosition().setY(b->getPosition().y() + (b->getVelocity().y()));
    }

    //update position and slow velocity due to friction
    for(int i = 0; i < m_balls.size(); i++){
        Ball *b = m_balls.at(i);


        if(b->getVelocity().x() > 0){
            b->getVelocity().setX(b->getVelocity().x()-m_table->getFriction());
        }
        if(b->getVelocity().x() < 0){
            b->getVelocity().setX(b->getVelocity().x()+m_table->getFriction());
        }
        if(b->getVelocity().y() > 0){
            b->getVelocity().setY(b->getVelocity().y()-m_table->getFriction());
        }
        if(b->getVelocity().y() < 0){
            b->getVelocity().setY(b->getVelocity().y()+m_table->getFriction());
        }
        if(std::abs(b->getVelocity().x()) < 0.1){
            b->getVelocity().setX(0);
        }
        if(std::abs(b->getVelocity().y()) < 0.1){
            b->getVelocity().setY(0);
        }

    }
}

bool Dialog::ballCollision(Ball *b1, Ball *b2)
{
    return ((b1->getPosition().distanceToPoint(b2->getPosition()) <= b1->radius()) || (b1->getPosition().distanceToPoint(b2->getPosition())) <= b2->radius());
}

void Dialog::handleBallCollision(Ball *b1, Ball *b2)
{
    //QVector2D is a QT class representing a vector in 2D space,
    //it has useful functions like dotproduct(), length() and normalize().
    //You don't need to use it if you would rather do this yourself
    //Properties of two colliding balls,
    //ball A
    QVector2D posA = b1->getPosition();
    QVector2D velA = b1->getVelocity();
    float massA = b1->mass();
    //and ball B
    QVector2D posB = b2->getPosition();
    QVector2D velB = b2->getVelocity();
    float massB = b2->mass();

    //calculate their mass ratio
    float mR = massB / massA;

    //calculate the axis of collision
    QVector2D collisionVector = posB - posA;
    collisionVector.normalize();

   //the proportion of each balls velocity along the axis of collision
    double vA = QVector2D::dotProduct(collisionVector, velA);
    double vB = QVector2D::dotProduct(collisionVector, velB);
    //the balls are moving away from each other so do nothing
    if (vA <= 0 && vB >= 0) {
     return;
    }

    //The velocity of each ball after a collision can be found by solving the quadratic equation
    //given by equating momentum and energy before and after the collision and finding the velocities
    //that satisfy this
    //-(mR+1)x^2 2*(mR*vB+vA)x -((mR-1)*vB^2+2*vA*vB)=0
    //first we find the discriminant
    double a = -(mR + 1);
    double b = 2 * (mR * vB + vA);
    double c = -((mR - 1) * vB * vB + 2 * vA * vB);
    double discriminant = sqrt(b * b - 4 * a * c);
    double root = (-b + discriminant)/(2 * a);
    //only one of the roots is the solution, the other pertains to the current velocities
    if (root - vB < 0.01) {
      root = (-b - discriminant)/(2 * a);
    }


    //The resulting changes in velocity for ball A and B
    QVector2D deltaVA = mR * (vB - root) * collisionVector;
    QVector2D deltaVB = (root - vB) * collisionVector;
    b1->getVelocity().setX(b1->getVelocity().x() + deltaVA.x());
    b1->getVelocity().setY(b1->getVelocity().y() + deltaVA.y());
    b2->getVelocity().setX(b2->getVelocity().x() + deltaVB.x());
    b2->getVelocity().setY(b2->getVelocity().y() + deltaVB.y());
}


bool Dialog::isTopCollision(Ball *b)
{
    return b->getPosition().y() < 0 + b->radius();
}

bool Dialog::isBottomCollision(Ball *b)
{
    return b->getPosition().y() > m_table->getHeight() - b->radius();
}

bool Dialog::isLeftCollision(Ball *b)
{
    return b->getPosition().x() < 0 + b->radius();
}

bool Dialog::isRightCollision(Ball *b)
{
    return b->getPosition().x() > m_table->getWidth() - b->radius();
}



