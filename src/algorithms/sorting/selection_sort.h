#pragma once

#ifndef SWAP
    #define SWAP(x, y, T) do{T t = x; x = y; y = t;}while(0)
#endif

template <typename T> struct CSelectionSort
{
    typedef bool(*fnc_cmp_const)(const T &, const T &);

    static void sort(T * data, size_t n, fnc_cmp_const fnc)
    {
        for (size_t i = 0, min = 0; i < n; ++i, min = i)
        {
            for (size_t j = i + 1; j < n; ++j)
            {
                if (fnc(data[j], data[min])) min = j;
            }

            SWAP(data[i], data[min], T);
        }
    }
};