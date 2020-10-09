#include "kitchen.h"
#include <cstdlib>
#include <assert.h>

Kitchen::Kitchen()
{
    m_milk = 1;
}

bool Kitchen::drinkMilkAndBuyIfNeeded()
{
    // drink milk with approximately probability of 20%
    bool drinkMilk = rand() % 100 < 20;
    bool bought = false;

    if (!drinkMilk)
        return false;

    m_lock.acquire();
    m_milk--;
    if (m_milk == 0) {
        m_milk++;
     bought = true;
    }
    m_lock.release();

    assert(m_milk >= 0 && m_milk <= 1);

    return bought;
}
