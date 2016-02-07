#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include "Sorts.h"

const size_t length = 20;
const char char_offset = 64;

unsigned read_uint(std::istream& the_stream)
{
    unsigned n;
    the_stream >> n;
    return n;
}

int main(int argc, char** argv)
{

    clock_t duration;

    string cache (length, char_offset);
    for(unsigned i = cache.size(); i > 0; i--) cache[i-1] += i;

    std::cout << "Size of the vector: ";
    vector<std::string> items(read_uint(std::cin));
    vector<std::string> items_tb_sorted(items.size());

    for(unsigned i = items.size(); i > 0; i--)
    {
        std::random_shuffle(cache.begin(), cache.end());
        items[i-1] = cache;
    }

    cache.clear();

    items_tb_sorted = items;
    duration = std::clock();
    SelectionSort(items_tb_sorted);
    duration = std::clock() - duration;
    std::cout << "Selection Sort:\t" << \
    ((float)(duration))/CLOCKS_PER_SEC*1000.0 << " ms" << endl;

    items_tb_sorted = items;
    duration = std::clock();
    MergeSort(items_tb_sorted);
    duration = std::clock() - duration;
    std::cout << "Merge Sort:\t" << \
    ((float)(duration))/CLOCKS_PER_SEC*1000.0 << " ms" << endl;

    vector<string>().swap(items);
    vector<string>().swap(items_tb_sorted);
    return 0;
}
