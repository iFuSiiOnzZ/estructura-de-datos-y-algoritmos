
#include "algorithms\data\stack.h"
#include "tests\stack.h"

#include "algorithms\data\queue.h"
#include "tests\queue.h"

#include "algorithms\sorting\selection_sort.h"
#include "tests\selection_sort.h"

#include "algorithms\sorting\insertion_sort.h"
#include "tests\insertion_sort.h"

#include "algorithms\sorting\merge_sort.h"
#include "tests\merge_sort.h"

#include "algorithms\sorting\quick_sort.h"
#include "tests\quick_sort.h"

#include "algorithms\data\binary_search_tree.h"
#include "tests\binary_search_tree.h"

 #ifndef UNUSED
    #define UNUSED(x) (void)x
#endif

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    test_stack();
    test_queue();

    test_binary_tree();

    test_selection_sort();
    test_insertion_sort();

    test_merge_sort();
    test_quick_sort();

    return 0;
}