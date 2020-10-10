

<details>
  <summary>Exercise 12 (branch 5.12)</summary>
  
  In Section 5.1.3, we presented a solution to the Too Much Milk problem. To make the problem
more interesting, we will also allow roommates to drink milk.
Implement in C++ or Java a Kitchen class with a drinkMilkAndBuyIfNeeded(). This method
should randomly (with a 20% probability) change the value of milk from 1 to 0. Then, if the
value just became 0, it should buy milk (incrementing milk back to 1). The method should return
1 if the roommate bought milk and 0 otherwise.
Your solution should use locks for synchronization and work for any number of roommates. Test
your implementation by writing a program that repeatedly creates a Kitchen object and varying
numbers of roommate threads; each roommate thread should call drinkMilkAndBuyIfNeeded()
multiple times in a loop.
Hint: You will probably write a main() thread that creates a Kitchen object, creates multipleroommate threads, and then waits for all of the roommates to finish their loops. If you are writing
in C++ with the POSIX threads library, you can use pthread_join() to have one thread wait for
another thread to finish. If you are writing in Java with the java.lang.Thread class, you can use
the join() method.
  
</details>

<details>
<summary>Exercise 13 (main branch)</summary>
For the solution to Too Much Milk suggested in the previous problem, each call to
drinkMilkAndBuyIfNeeded() is atomic and holds the lock from the start to the end even if one
roommate goes to the store. This solution is analogous to the roommate padlocking the kitchen
while going to the store, which seems a bit unrealistic.
Implement a better solution to drinkMilkAndBuyIfNeeded() using both locks and condition
variables. Since a roommate now needs to release the lock to the kitchen while going to the
store, you will no longer acquire the lock at the start of this function and release it at the end.
Instead, this function will call two helper-functions, each of which acquires/releases the lock.
For example:

```c++
int Kitchen::drinkMilkAndBuyIfNeeded() {
    int iShouldBuy = waitThenDrink();
        if (iShoudBuy) {
        buyMilk();
    }
}
```

In this function, waitThenDrink() should wait if there is no milk (using a condition variable)
until there is milk, drink the milk, and if the milk is now gone, return a nonzero value to flag that
the caller should buy milk. BuyMilk() should buy milk and then broadcast to let the waiting
threads know that they can proceed.
Again, test your code with varying numbers of threads.
</details>
