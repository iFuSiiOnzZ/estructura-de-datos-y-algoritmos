#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

static inline bool cmp_less_ms(const int &a, const int &b)
{
    return a < b;
}

static inline bool cmp_greater_ms(const int &a, const int &b)
{
    return a > b;
}

void test_merge_sort()
{
    int arr[5] = { 4, 1, 0, 3, 2 };

    CMergeSort<int>::sort(arr, 5, cmp_less_ms);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == i, "Sorting not correct");
    }

    CMergeSort<int>::sort(arr, 5, cmp_greater_ms);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == 4 - i, "Sorting not correct");
    }
}