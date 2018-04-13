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
    ui(new Ui::Dialog),
    game(this)
{

    ui->setupUi(this);

    Table *table = game.getTable();
    this->resize(table->getWidth(), table->getHeight());

    //drawing the table
    this->setStyleSheet((std::string("background-color: ") + table->getColour().toStdString()).c_str());
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(nextAnim()));

    //timer for updating graphics
    timer->start(32);

    //timer for updating physics
    timer2->start(32);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    game.drawBalls(painter);
}

void Dialog::nextAnim()
{
    game.updatePhysics();
}




