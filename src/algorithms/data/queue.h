#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

template <typename T> class CQueue
{
    private:
        T *m_DataContainer;
        size_t m_Head, m_Tail;
        size_t m_ContainerSize, m_Count;

    private:
        void ResizeArray(size_t NewSize)
        {
            T *NewDataContainer = new T[NewSize];
            ASSERT(NewDataContainer, "Queue container could not be resized");

            for (size_t i = 0; i < m_Count; ++i)
            {
                size_t s = (m_Head + i + 1) % m_ContainerSize;
                NewDataContainer[i] = m_DataContainer[s];
            }

            m_Tail = m_Count - 1;
            m_ContainerSize = NewSize;
            m_Head = m_ContainerSize - 1;

            delete[] m_DataContainer;
            m_DataContainer = NewDataContainer;
        }

    public:
        CQueue()
        {
            m_ContainerSize = 2, m_Count = 0;
            m_Head = m_Tail = m_ContainerSize - 1;
            
            m_DataContainer = new T[m_ContainerSize];
            ASSERT(m_DataContainer, "Queue container could not be created");
        }

        ~CQueue()
        {
            delete[] m_DataContainer;
            m_DataContainer = nullptr;

           m_Head = m_Tail = m_Count = 0;
            m_ContainerSize = 0;
        }

        size_t size()
        {
            return m_Count;
        }

        bool empty()
        {
            return m_Count == 0;
        }

        void push(T Element)
        {
            if (m_Count == m_ContainerSize) ResizeArray(m_ContainerSize * 2);
            ++m_Count;
            
            m_Tail = (m_Tail + 1) % m_ContainerSize;
            m_DataContainer[m_Tail] = Element;
        }

        T pop()
        {
            ASSERT(m_Count, "Queue is empty");
            m_Head = (m_Head + 1) % m_ContainerSize;

            T Element = m_DataContainer[m_Head];
            --m_Count;

            if (m_Count == m_ContainerSize / 4) ResizeArray(m_ContainerSize / 2);
            return Element;
        }
};