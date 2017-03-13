#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

void test_queue()
{
    CQueue<int> queue;
    int num_values = 50;

    for (int i = 0; i < num_values; ++i)
    {
        queue.push(i);
    }

    for (int i = 0; i < num_values; ++i)
    {
        int t = queue.pop();
        ASSERT(t == i, "Pop value not igual");
    }

    for (int i = 0; i < num_values; ++i)
    {
        queue.push(i);
    }

    while (!queue.empty())
    {
        queue.pop();
    }

    ASSERT(!queue.size(), "Queue sould be empty");


    for (int i = 0; i < 5; ++i)
    {
        queue.push(i);
    }

    ASSERT(queue.pop() == 0, "Pop value not equal");
    ASSERT(queue.pop() == 1, "Pop value not equal");

    queue.push(0);
    queue.push(1);

    ASSERT(queue.pop() == 2, "Pop value not equal");
    ASSERT(queue.pop() == 3, "Pop value not equal");
    ASSERT(queue.pop() == 4, "Pop value not equal");

    ASSERT(queue.pop() == 0, "Pop value not equal");
    ASSERT(queue.pop() == 1, "Pop value not equal");

    ASSERT(!queue.size(), "Queue should be empty");

    for (int i = 0; i < num_values; ++i)
    {
        queue.push(i);
    }

    while (!queue.empty())
    {
        queue.pop();
    }

    ASSERT(!queue.size(), "Queue should be empty");
}