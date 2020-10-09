#ifndef KITCHEN_H
#define KITCHEN_H

#include "3rdparty/Lock.h"

class Kitchen
{
public:
    Kitchen();

    bool drinkMilkAndBuyIfNeeded();

private:
    int m_milk;
    Lock m_lock;
};

#endif // KITCHEN_H
