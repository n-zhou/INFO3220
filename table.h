#ifndef TABLE_H
#define TABLE_H

#include <QString>

class Table {
public:
    Table():
    m_colour(QString("blue")),
    m_width(600),
    m_height(300),
    m_friction(0.1){}

    Table(QString colour,
          double width,
          double height,
          double friction):
        m_colour(colour),
        m_width(width),
        m_height(height),
        m_friction(friction){}

    virtual ~Table(){}

    virtual QString getColour() = 0;
    virtual double getWidth(){return m_width;}
    virtual double getHeight(){return m_height;}
    virtual double getFriction(){return m_friction;}

protected:
    QString m_colour;
    double m_width;
    double m_height;
    double m_friction;
};

#endif //TABLE_H
