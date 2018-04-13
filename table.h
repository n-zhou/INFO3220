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

    /**
     * @brief ~Table has no memory to cleanup so the destructor
     * should be empty.
     */
    virtual ~Table(){}

    /**
     * @brief subclasses must implement this method in order to
     * inherit from this class.
     * @return a QString representation of colour
     */
    virtual QString getColour() = 0;

    /**
     * @brief getWidth
     * @return the width of the ball.
     */
    virtual double getWidth(){return m_width;}

    /**
     * @brief getHeight
     * @return the height of the ball.
     */
    virtual double getHeight(){return m_height;}

    /**
     * @brief getFriction
     * @return the friction of the table
     */
    virtual double getFriction(){return m_friction;}

protected:
    QString m_colour;
    double m_width;
    double m_height;
    double m_friction;
};

#endif //TABLE_H
