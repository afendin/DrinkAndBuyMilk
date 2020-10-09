### My solution to execise#12(5th chapter) from book "Operating Systems: Principles and Practice 2nd Edition"

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