#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include "table.h"
#include <string>
//#include "config.h"
#include "game.h"
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
    Game game;

    /**
     * @brief paintEvent is called by the slot Dialog::nextFrame()
     * to update the position of the balls on screen.
     * @param event
     */
    void paintEvent(QPaintEvent *event);

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
