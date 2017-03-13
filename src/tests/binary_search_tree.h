#pragma once

#ifndef ASSERT
    #define ASSERT(x, msg) if(!(x)){*(int *)0 = 0;}
#endif


void test_binary_tree()
{
    CBinarySearchTree<int> tree;
    bst_array_t<int> arr = { 0 };

    tree.insert(5);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);

    arr = tree.to_array();
    ASSERT(arr.NumElements == 7, "Elements missong");

    ASSERT(arr.data[0] == 2, "Not equal");
    ASSERT(arr.data[1] == 3, "Not equal");
    ASSERT(arr.data[2] == 4, "Not equal");
    ASSERT(arr.data[3] == 5, "Not equal");
    ASSERT(arr.data[4] == 6, "Not equal");
    ASSERT(arr.data[5] == 7, "Not equal");
    ASSERT(arr.data[6] == 8, "Not equal");

    tree.remove(2);
    arr = tree.to_array();
    ASSERT(arr.NumElements == 6, "Elements missong");

    ASSERT(arr.data[0] == 3, "Not equal");
    ASSERT(arr.data[1] == 4, "Not equal");
    ASSERT(arr.data[2] == 5, "Not equal");
    ASSERT(arr.data[3] == 6, "Not equal");
    ASSERT(arr.data[4] == 7, "Not equal");
    ASSERT(arr.data[5] == 8, "Not equal");

    tree.remove(3);
    arr = tree.to_array();
    ASSERT(arr.NumElements == 5, "Elements missong");

    ASSERT(arr.data[0] == 4, "Not equal");
    ASSERT(arr.data[1] == 5, "Not equal");
    ASSERT(arr.data[2] == 6, "Not equal");
    ASSERT(arr.data[3] == 7, "Not equal");
    ASSERT(arr.data[4] == 8, "Not equal");

    tree.remove(5);
    arr = tree.to_array();
    ASSERT(arr.NumElements == 4, "Elements missong");

    ASSERT(arr.data[0] == 4, "Not equal");
    ASSERT(arr.data[1] == 6, "Not equal");
    ASSERT(arr.data[2] == 7, "Not equal");
    ASSERT(arr.data[3] == 8, "Not equal");

    int ar[3] = { 1, 2, 3 };
    tree.from_array(ar, 3);

    arr = tree.to_array();
    ASSERT(arr.NumElements == 3, "Elements missong");

    ASSERT(arr.data[0] == 1, "Not equal");
    ASSERT(arr.data[1] == 2, "Not equal");
    ASSERT(arr.data[2] == 3, "Not equal");

}