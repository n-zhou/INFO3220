#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "table.h"
#include <string>
//#include "config.h"
#include "concretepoolfactory.h"
#include <vector>
#define CONFIG_FILE "../PoolGame/config.json"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void checkCollision();


private:
    Ui::Dialog *ui;
    void init();
    void paintEvent(QPaintEvent *event);
    Table *m_table;
    std::vector<Ball*> m_balls;
    bool ballCollision(Ball *b1, Ball *b2);
    void handleBallCollision(Ball *b1, Ball *b2);
    bool isCollision(Ball *b);
    bool isTopCollision(Ball *b);
    bool isBottomCollision(Ball *b);
    bool isLeftCollision(Ball *b);
    bool isRightCollision(Ball *b);

public slots:
    /**
     * @brief nextFrame is responsible for updating
     * the balls on the screen.
     */
    void nextFrame();

    /**
     * @brief nextAnim is responsible for updating the
     * physics of the balls.
     */
    void nextAnim();
};

#endif // DIALOG_H
