#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

#include <stdio.h>

void test_ordered_array()
{
    COrderedArray<int> OrderedArray;
    size_t i = 0;

    for(int i = 0; i < 10; ++i)
    {
        OrderedArray.push(i);
    }

    for(int i = 20 - 1 ; i >= 10; --i)
    {
        OrderedArray.push(i);
    }

    for(int i = 0; i < OrderedArray.size(); ++i)
    {
        ASSERT(OrderedArray[i] == i, "Values are not equal");
    }

    OrderedArray.pop();
    OrderedArray.pop();
    OrderedArray.pop();
    OrderedArray.pop();

    for (int i = 0; i < OrderedArray.size(); ++i)
    {
        ASSERT(OrderedArray[i] == i, "Values are not equal");
    }

    ASSERT(OrderedArray[10] == 10, "Not equals");
    ASSERT(OrderedArray[ 0] ==  0, "Not equals");
    ASSERT(OrderedArray[15] == 15, "Not equals");
    ASSERT(OrderedArray[ 5] ==  5, "Not equals");

    i = OrderedArray.search(5);
    ASSERT(i != -1, "Element not found");
    
    i = OrderedArray.search(0);
    ASSERT(i != -1, "Element not found");

    // NOTE(Andrei): size_t -1 == 0xFFFFFFFFFFFFFFFF;
    ASSERT(OrderedArray.search(60) == -1, "Element found, but shound exists");
}