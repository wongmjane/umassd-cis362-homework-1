#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include "Sorts.h"

int main(int argc, char** argv)
{
    clock_t duration;
    size_t n;

    vector<int> items, items_tb_sorted;

    std::cout << "N,SelectionSort,SelectionSorted,MergeSort,MergeSorted";

    for(unsigned n = 1; n <= 10000; n++)
    {
        cout << endl << n << ',';
        items.resize(n);
        items_tb_sorted.resize(n);
        for(unsigned i = items.size(); i > 0; i--) items[i-1] = i;
        std::random_shuffle(items.begin(), items.end());
        items_tb_sorted = items;
        duration = std::clock();
        SelectionSort(items_tb_sorted);
        duration = std::clock() - duration;
        cout << ((float)duration)/CLOCKS_PER_SEC*1000.0 << ',';
        duration = std::clock();
        SelectionSort(items_tb_sorted);
        duration = std::clock() - duration;
        cout << ((float)duration)/CLOCKS_PER_SEC*1000.0 << ',';
        items_tb_sorted = items;
        duration = std::clock();
        MergeSort(items_tb_sorted);
        duration = std::clock() - duration;
        cout << ((float)duration)/CLOCKS_PER_SEC*1000.0 << ',';
        duration = std::clock();
        MergeSort(items_tb_sorted);
        duration = std::clock() - duration;
        cout << ((float)duration)/CLOCKS_PER_SEC*1000.0;
        items.clear();
        items_tb_sorted.clear();
    }

    vector<int>().swap(items);
    vector<int>().swap(items_tb_sorted);
    return 0;
}
