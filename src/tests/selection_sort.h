#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

static inline bool cmp_less_ss(const int &a, const int &b)
{
    return a < b;
}

static inline bool cmp_greater_ss(const int &a, const int &b)
{
    return a > b;
}

void test_selection_sort()
{
    int arr[5] = { 4, 1, 0, 3, 2 };
    
    CSelectionSort<int>::sort(arr, 5, cmp_less_ss);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == i, "Sorting not correct");
    }

    CSelectionSort<int>::sort(arr, 5, cmp_greater_ss);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == 4 - i, "Sorting not correct");
    }
}