#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDialog>
#include <cmath>
#include <QDebug>
#include <vector>
#include "ball.h"
#include "table.h"
#include "abstractpool.h"
#define CONFIG_FILE "../PoolGame/config.json"
#define TEST_CONFIG "../PoolGame/test.json"

class Game
{
public:
    Game(QDialog*);

    ~Game();


    /**
     * @brief drawBalls draws all the balls on the table and screen.
     */
    void drawBalls(QPainter&);

    /**
     * @brief updatePhysics updates the properties of all the balls
     * such as position and velocity and applies those changes.
     */
    void updatePhysics();

    /**
     * @brief setTable is a setter
     * @param table
     */
    void setTable(Table* table);
    Table* getTable();

private:
    Table *m_table;
    std::vector<Ball*> m_balls;
    QDialog *m_dialog;


    /**
    * @brief Game::ballCollision will check if two balls collide.
    * @param b1 The first ball we are checking
    * @param b2 The second ball we are checking
    * @return true if they are colliding, false otherwise
    */
    bool ballCollision(Ball *b1, Ball *b2);


    /**
     * @brief Game::handleBallCollision will apply the change in velocity of 2 colliding balls
     * @param b1
     * @param b2
     */
    void handleBallCollision(Ball *b1, Ball *b2);

    /**
     * @brief Game::isTopCollision
     * @param b
     * @return true if b is hitting the top edge
     */
    bool isTopCollision(Ball *b);

    /**
     * @brief Game::isBottomCollision
     * @param b
     * @return true if b is hitting the bottom edge
     */
    bool isBottomCollision(Ball *b);

    /**
     * @brief Game::isLeftCollision
     * @param b
     * @return true if b is hitting the left edge
     */
    bool isLeftCollision(Ball *b);

    /**
     * @brief Game::isRightCollision
     * @param b
     * @return true if b is hitting the right edge
     */
    bool isRightCollision(Ball *b);
};

#endif // GAME_H
