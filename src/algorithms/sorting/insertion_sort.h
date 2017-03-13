#pragma once

#ifndef SWAP
    #define SWAP(x, y, T) do{T t = x; x = y; y = t;}while(0)
#endif

template <typename T> struct CInsertionSort
{
    typedef bool(*fnc_cmp_const)(const T &, const T &);

    static void sort(T * data, size_t n, fnc_cmp_const fnc)
    {
        for (size_t i = 0; i < n; ++i) for (size_t j = i; j > 0; --j)
        {
            if (fnc(data[j], data[j - 1])) SWAP(data[j], data[j - 1], int);
            else break;
        }
    }
};