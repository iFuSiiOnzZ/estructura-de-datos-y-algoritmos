#pragma once

#ifndef SWAP
    #define SWAP(x, y, T) do{T t = x; x = y; y = t;}while(0)
#endif

template <typename T> struct CQuickSort
{
    typedef bool(*fnc_cmp_const)(const T &, const T &);

    static void sort(T * data, size_t n, fnc_cmp_const fnc)
    {
        sort(data, 0, n - 1, fnc);
    }

    private:
        static void sort(T * data, size_t lo, size_t hi, fnc_cmp_const fnc)
        {
            if (lo >= hi) return;
            size_t p = partition(data, lo, hi, fnc);

            if (p > 0)
            {
                sort(data, lo, p - 1, fnc);
            }

            if (p < hi)
            {
                sort(data, p + 1, hi, fnc);
            }
        }

        static size_t partition(T *data, size_t lo, size_t hi, fnc_cmp_const fnc)
        {
            size_t left = lo, right = hi + 1;
            const T & pivot = data[lo];

            while (1)
            {
                while (fnc(data[++left], pivot))
                {
                    if (left == hi) break;
                }

                while (fnc(pivot, data[--right]))
                {
                    if (right == lo) break;
                }

                if (left >= right) break;
                SWAP(data[left], data[right], T);
            }

            SWAP(data[lo], data[right], T);
            return right;
        }
};