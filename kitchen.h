#ifndef KITCHEN_H
#define KITCHEN_H

#include "3rdparty/Lock.h"
#include "3rdparty/CV.h"

class Kitchen
{
public:
    Kitchen();

    bool waitThenDrink();
    void buyMilk();
    void drinkMilkAndBuyIfNeeded(int roommate);

private:
    int m_milk;
    Lock m_lock;
    CV m_haveMilk;
};

#endif // KITCHEN_H
