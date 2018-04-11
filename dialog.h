#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "table.h"
#include <string>
//#include "config.h"
#include "concretepoolfactory.h"
#include <vector>

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
    //void handleBallCollision(Ball *b1, Ball *b2);
    bool isCollision(Ball *b);
    bool isTopCollision(Ball *b);
    bool isBottomCollision(Ball *b);
    bool isLeftCollision(Ball *b);
    bool isRightCollision(Ball *b);

public slots:
    void nextFrame();
    void nextAnim();
};

#endif // DIALOG_H
