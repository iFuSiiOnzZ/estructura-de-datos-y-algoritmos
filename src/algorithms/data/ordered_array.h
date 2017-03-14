#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

template <typename T> class COrderedArray
{
    private:
        T *m_DataContainer;
        size_t m_NumElements;
        size_t m_ContainerSize;

    private:
        void ResizeArray(size_t NewSize)
        {
            m_ContainerSize = NewSize;
            T *NewDataContainer = new T[NewSize];

            ASSERT(NewDataContainer, "OrderedArray container could not be resized");
            for (size_t i = 0; i < m_NumElements; ++i) NewDataContainer[i] = m_DataContainer[i];

            delete[] m_DataContainer;
            m_DataContainer = NewDataContainer;
        }

    public:
        COrderedArray()
        {
            m_ContainerSize = 2, m_NumElements = 0;
            m_DataContainer = new T[m_ContainerSize];
            ASSERT(m_DataContainer, "OrderedArray container could not be created");
        }

        ~COrderedArray()
        {
            delete [] m_DataContainer;
            m_DataContainer = nullptr;

            m_ContainerSize = 0;
            m_NumElements = 0;
        }

        inline size_t size()
        {
            return m_NumElements;
        }

        inline bool empty()
        {
            return m_NumElements == 0;
        }

        inline T &operator[](size_t Index)
        {
            ASSERT(Index <= m_NumElements, "Index out of range");
            return m_DataContainer[Index];
        }

        inline void pop()
        {
            m_NumElements = m_NumElements ? m_NumElements - 1 : 0;
        }

        void push(T Element)
        {
            if (m_NumElements == m_ContainerSize) ResizeArray(2 * m_ContainerSize);
            size_t InsertPosition = 0;

            while(InsertPosition < m_NumElements && Element > m_DataContainer[InsertPosition])
            {
                ++InsertPosition;
            }

            for(size_t k = m_NumElements; k > InsertPosition; --k)
            {
                m_DataContainer[k] = m_DataContainer[k - 1];
            }

            m_DataContainer[InsertPosition] = Element;
            ++m_NumElements;
        }

        size_t search(T Element)
        {
            size_t lo = 0;
            size_t hi = m_NumElements - 1;

            while(1)
            {
                size_t current = (lo + hi) / 2;

                if(m_DataContainer[current] == Element)
                {
                    return current;
                }
                else if(lo >= hi)
                {
                    return -1;
                }
                else
                {
                    if(m_DataContainer[current] < Element) lo = current + 1;
                    else hi = current - 1;
                }
            }

            return -1;
        }
};