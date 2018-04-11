#ifndef POOLTABLE_H
#define POOLTABLE_H

#include "table.h"

class PoolTable : public Table
{
public:
    PoolTable(QString colour,
              unsigned int width,
              unsigned int height,
              double friction);

    ~PoolTable();

    QString getColour();
};

#endif // POOLTABLE_H
