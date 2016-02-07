#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include "Sorts.h"

// reads then returns an unsigned integer from an std::istream
unsigned read_uint(std::istream& the_stream)
{
    unsigned n;
    the_stream >> n;
    return n;
}

int main(int argc, char** argv)
{

    clock_t duration;

    // prompt user for the number of items to be sorted
    std::cout << "Number of items: ";

    // declare a vector of integers with a user-inputted size
    vector<int> items(read_uint(std::cin)),
                items_tb_sorted(items.size());

    // fill the vector "items" with a sequence of integers
    for(unsigned i = items.size(); i > 0; i--) items[i-1] = i;

    // shuffle the vector "items" randomly
    std::random_shuffle(items.begin(), items.end());

    // replace contents of "items_tb_sorted" with duplicated contents of "items"
    items_tb_sorted = items;

    // assign duration offset
    duration = std::clock();

    // selection sort "items_tb_sorted"
    SelectionSort(items_tb_sorted);

    duration = std::clock() - duration;

    // display duration of selection-sorting "items_tb_sorted" in miliseconds
    std::cout << "Selection Sort:\t" << \
    ((float)(duration))/CLOCKS_PER_SEC*1000.0 << " ms" << endl;

    // replace contents of "items_tb_sorted" with duplicated contents of "items"
    items_tb_sorted = items;

    // assign duration offset
    duration = std::clock();

    // merge sort "items_tb_sorted"
    MergeSort(items_tb_sorted);

    duration = std::clock() - duration;

    // display duration of merge-sorting "items_tb_sorted" in miliseconds
    std::cout << "Merge Sort:\t" << \
    ((float)(duration))/CLOCKS_PER_SEC*1000.0 << " ms" << endl;

    vector<int>().swap(items);
    vector<int>().swap(items_tb_sorted);
    return 0;
}
