// Sorts.h      
//////////////////////////////////////////////////////////

#include <vector>
using namespace std;

template <class Comparable> 
void SelectionSort(vector<Comparable> & nums, int low, int high)
{
    for (int i = low; i <= high-1; i++) {
        int indexOfMin = i;                     // traverse the list to
        for (int j = i+1; j <= high; j++) {     // find the index of the
            if (nums[j] < nums[indexOfMin]) {   // next smallest item
                indexOfMin = j;
            }
        }

        Comparable temp = nums[i];              // swap the next smallest
        nums[i] = nums[indexOfMin];             // item into its correct
        nums[indexOfMin] = temp;                // position
    }
}

template <class Comparable> void SelectionSort(vector<Comparable> & nums) 
{
    SelectionSort(nums, 0, nums.size()-1);
}

///////////////////////////////////////////////////////////////////

template <class Comparable> 
void Merge(vector<Comparable> & nums, int low, int high)
{
    vector<Comparable> copy;
    int size = high-low+1, middle = 1 + (low+high)/2;  // middle rounds up if even
    int front1 = low, front2 = middle;
    for (int i = 0; i < size; i++) {
        if (front2 > high || (front1 < middle && nums[front1] < nums[front2])) {
            copy.push_back(nums[front1]);
            front1++;
        }
        else {
            copy.push_back(nums[front2]);
            front2++;
        }
    }

    for (int k = 0; k < size; k++) {
        nums[low+k] = copy[k];
    }
}

template <class Comparable> 
void MergeSort(vector<Comparable> & nums, int low, int high) 
{
    if (low < high) {
        int middle = (low + high)/2;
        MergeSort(nums, low, middle);
        MergeSort(nums, middle+1, high);
        Merge(nums, low, high);
    }
}



template <class Comparable> void MergeSort(vector<Comparable> & nums) 
{
    MergeSort(nums, 0, nums.size()-1);
}
