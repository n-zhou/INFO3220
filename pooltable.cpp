#include "pooltable.h"

PoolTable::PoolTable(QString colour, unsigned int width, unsigned int height, double friction):
    Table(colour, width, height, friction){}

PoolTable::~PoolTable(){}

QString PoolTable::getColour()
{
    return m_colour;
}
