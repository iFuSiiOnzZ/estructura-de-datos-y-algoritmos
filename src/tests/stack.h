#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

void test_stack()
{
    CStack<int> stack;
    int num_values = 100;

    for (int i = 0; i < num_values; ++i)
    {
        stack.push(i);
    }

    for (int i = num_values - 1; i > 0; --i)
    {
        ASSERT(stack.pop() == i, "Pop value from stack not igual");
    }

    for (int i = 0; i < num_values; ++i)
    {
        stack.push(i);
    }

    while (!stack.empty())
    {
        stack.pop();
    }

    ASSERT(!stack.size(), "Stack sould be empty");
}