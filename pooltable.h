#ifndef POOLTABLE_H
#define POOLTABLE_H

#include "table.h"

class PoolTable : public Table
{
public:
    /**
     * @brief PoolTable constructs a concrete Table with the given parameters.
     * @param colour
     * @param width
     * @param height
     * @param friction
     */
    PoolTable(QString colour,
              unsigned int width,
              unsigned int height,
              double friction);


    ~PoolTable();

    /**
     * @brief getColour is implemented in order to inherit
     * from Table.
     * @return a QString respresentaion of the table colour.
     */
    QString getColour();
};

#endif // POOLTABLE_H
