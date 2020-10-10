#include "kitchen.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Kitchen::Kitchen()
{
    m_milk = 1;
}

bool Kitchen::waitThenDrink()
{
    // drink milk with approximately probability of 20%
    bool drinkMilk = rand() % 100 < 20;
    if (!drinkMilk)
        return false; //shouldn't buy

    m_lock.acquire();
    while (m_milk < 1) {
        m_haveMilk.wait(&m_lock);
    }

    m_milk--;
    m_lock.release();

    return true; //should buy
}

void Kitchen::buyMilk()
{
    m_lock.acquire();
    m_milk++;
    m_haveMilk.signal();
    m_lock.release();
}

void Kitchen::drinkMilkAndBuyIfNeeded(int roommate)
{
    assert(m_milk >= 0 && m_milk <= 1);

    bool iShouldBuy = waitThenDrink();

    if (iShouldBuy) {
        buyMilk();
        printf("Roommate %d bought milk.\n", roommate);
        return;
    }

    printf("Roommate %d didn't buy milk.\n", roommate);
}
