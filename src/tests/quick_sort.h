#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

static inline bool cmp_less_qs(const int &a, const int &b)
{
    return a < b;
}

static inline bool cmp_greater_qs(const int &a, const int &b)
{
    return a > b;
}

void test_quick_sort()
{
    int arr[5] = { 4, 1, 0, 3, 2 };

    CQuickSort<int>::sort(arr, 5, cmp_less_qs);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == i, "Sorting not correct");
    }

    CQuickSort<int>::sort(arr, 5, cmp_greater_qs);
    for (int i = 0; i < 5; ++i)
    {
        ASSERT(arr[i] == 4 - i, "Sorting not correct");
    }
}