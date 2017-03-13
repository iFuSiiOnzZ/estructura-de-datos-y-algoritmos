#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif

template <typename T> struct bst_node_t
{
    bst_node_t<T> *right;
    bst_node_t<T> *left;

    T data;
};

template <typename T> struct bst_array_t
{
    T *data;
    size_t NumElements;
};

template <typename T> class CBinarySearchTree
{
    private:
        bst_node_t<T> *m_RootNode;
        size_t m_size;

    private:
        void clear(bst_node_t<T> *node)
        {
            if (!node) return;

            clear(node->left);
            clear(node->right);

            delete node;
            node = nullptr;
        }

        bst_node_t<T> *CreateNode(T data, bst_node_t<T> *left = nullptr, bst_node_t<T> *right = nullptr)
        {
            bst_node_t<T> *NewNode = new bst_node_t<T>;
            ASSERT(NewNode, "Memory can not be allocated");

            NewNode->right = right;
            NewNode->left = left;

            NewNode->data = data;
            ++m_size;

            return NewNode;
        }

        bst_node_t<T> *GetNodeWithMinValue(bst_node_t<T> *node)
        {
            while (node->left != nullptr)
            {
                node = node->left;
            }

            return node;
        }

        bst_node_t<T> *insert(bst_node_t<T> *node, T data)
        {
            if (node == nullptr)
            {
                node = CreateNode(data, nullptr, nullptr);
            }
            else if (data < node->data)
            {
                node->left = insert(node->left, data);
            }
            else if (data > node->data)
            {
                node->right = insert(node->right, data);
            }

            return node;
        }

        bst_node_t<T> *remove(bst_node_t<T> *node, T data)
        {
            if (node == nullptr)
            {
                return node;
            }

            if (data < node->data)
            {
                node->left = remove(node->left, data);
            }
            else if (data > node->data)
            {
                node->right = remove(node->right, data);
            }
            else
            {
                if (node->left == nullptr && node->right == nullptr)
                {
                    --m_size;
                    delete node;
                    return nullptr;
                }
                else if (node->left == nullptr)
                {
                    bst_node_t<T> *t = node->right;
                    delete node;
                    
                    --m_size;
                    return t;
                }
                else if (node->right == nullptr)
                {
                    bst_node_t<T> *t = node->left;
                    delete node;
                    
                    --m_size;
                    return t;
                }

                bst_node_t<T> *t = GetNodeWithMinValue(node->right);
                node->data = t->data;
                node->right = remove(node->right, t->data);
            }

            return node;
        }

        size_t to_array(bst_node_t<T> *node, bst_array_t<T> *arr, size_t i = 0)
        {
            if (node == nullptr) return i;
            i = to_array(node->left, arr, i);
            
            arr->data[i] = node->data;
            i = to_array(node->right, arr, i + 1);

            return i;
        }

        bst_node_t<T> *from_array(T *arr, size_t start, size_t end)
        {
            if (start > end) return nullptr;

            size_t mid = (start + end) / 2;
            bst_node_t<T> *node = CreateNode(arr[mid]);

            if (mid != 0) node->left = from_array(arr, start, mid - 1);
            node->right = from_array(arr, mid + 1, end);

            return node;
        }

        size_t size(bst_node_t<T> *node)
        {
            return (node == nullptr) ? 0 : (1 + size(node->left) + size(node->right));
        }

    public:
        CBinarySearchTree() : m_RootNode(nullptr), m_size(0)
        {
        };

        ~CBinarySearchTree()
        {
            clear();
        }

        inline void clear()
        {
            m_size = 0;
            clear(m_RootNode);
            m_RootNode = nullptr;
        }

        inline void insert(T data)
        {
            m_RootNode = insert(m_RootNode, data);
        }

        inline void remove(T data)
        {
            m_RootNode = remove(m_RootNode, data);
        }

        inline size_t size()
        {
            return m_size;
        }

        inline void from_array(T *arr, size_t size)
        {
            clear();
            m_RootNode = from_array(arr, 0, size - 1);
        }

        inline bst_array_t<T> to_array()
        {
            bst_array_t<T> arr = { 0 };
            arr.NumElements = size();

            arr.data = new T[arr.NumElements];
            to_array(m_RootNode, &arr);

            return arr;
        }
};