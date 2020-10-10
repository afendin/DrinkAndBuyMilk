#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "3rdparty/thread.h"
#include "kitchen.h"

using namespace std;

Kitchen *kitchen;

void milkFunction(int threadNum);

int main()
{
    for (int i = 0; i < 1000; i++) {
        kitchen = new Kitchen;

        int numOfThreads = random() % 100;
        thread_t *roommates = new thread_t[numOfThreads];

        for (int j = 0; j < numOfThreads; j++)
            thread_create(&roommates[j], milkFunction, j);


        for (int j = 0; j < numOfThreads; j++)
            thread_join(roommates[j]);

        delete[] roommates;
        delete kitchen;
    }


    return 0;
}

void milkFunction(int threadNum)
{
    int drinkTimes = random() % 100;
    for (int i = 0; i < drinkTimes; i++) {
        kitchen->drinkMilkAndBuyIfNeeded(threadNum);
    }
}

