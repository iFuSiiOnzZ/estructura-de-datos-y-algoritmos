#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

template <typename T> class CStack
{
    private:
        T *m_DataContainer;
        size_t m_PushPosition;
        size_t m_ContainerSize;

    private:
        void ResizeArray(size_t NewSize)
        {
            m_ContainerSize = NewSize;
            T *NewDataContainer = new T[m_ContainerSize];

            ASSERT(NewDataContainer, "Stack container could not be resized");
            for (size_t i = 0; i < m_PushPosition; ++i) NewDataContainer[i] = m_DataContainer[i];

            delete[] m_DataContainer;
            m_DataContainer = NewDataContainer;
        }

    public:
        CStack()
        {
            m_PushPosition = 0;
            m_ContainerSize = 2;

            m_DataContainer = new T[m_ContainerSize];
            ASSERT(m_DataContainer, "Stack container could not be created");
        }

        ~CStack()
        {
            delete[] m_DataContainer;
            m_DataContainer = nullptr;

            m_PushPosition = 0;
            m_ContainerSize = 0;
        }

        size_t size()
        {
            return m_PushPosition;
        }

        bool empty()
        {
            return m_PushPosition == 0;
        }

        void push(T Element)
        {
            if (m_PushPosition == m_ContainerSize) ResizeArray(2 * m_ContainerSize);
            m_DataContainer[m_PushPosition++] = Element;
        }

        T pop()
        {
            ASSERT(m_PushPosition, "Stack is empty");
            T Element = m_DataContainer[--m_PushPosition];

            if (m_PushPosition == m_ContainerSize / 4) ResizeArray(m_ContainerSize / 2);
            return Element;
        }
};