#pragma once

template <typename T> struct CMergeSort
{
    typedef bool(*fnc_cmp_const)(const T &, const T &);

    static void sort(T * data, size_t n, fnc_cmp_const fnc)
    {
        T *aux = new T[n];

        sort(data, aux, 0, n - 1, fnc);

        delete[] aux;
    }

private:
    static void merge(T *data, T *aux, size_t lo, size_t mid, size_t hi, fnc_cmp_const fnc)
    {
        for (size_t k = lo; k <= hi; ++k)
        {
            aux[k] = data[k];
        }

        for (size_t k = lo, i = lo, j = mid + 1; k <= hi; ++k)
        {
                 if (i > mid)               data[k] = aux[j++];
            else if (j >  hi)               data[k] = aux[i++];
            else if (fnc(aux[j], aux[i]))   data[k] = aux[j++];
            else                            data[k] = aux[i++];
        }
    }

    static void sort(T * data, T *aux, size_t lo, size_t hi, fnc_cmp_const fnc)
    {
        if (hi <= lo) return;
        size_t mid = lo + (hi - lo) / 2;

        sort(data, aux, lo, mid, fnc);
        sort(data, aux, mid + 1, hi, fnc);

        if (fnc(data[mid], data[mid + 1])) return;
        merge(data, aux, lo, mid, hi, fnc);
    }
};