#include <algorithm>
#include <vector>
#include <iostream>


namespace QuickSort {

int partition(std::vector<int> &nums, int start, int end)
{
    const int midv = nums[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (nums[j] <= midv) {
            ++i;
            if (i != j) {
                std::swap(nums[i], nums[j]);
            }
        }
    }

    ++i;
    if (i != end) {
        std::swap(nums[i], nums[end]);
    }
    return i;
}

void quickSort(std::vector<int> &nums, int start, int end)
{
    if (start < end) {
        const int q = partition(nums, start, end);
        quickSort(nums, start, q - 1);
        quickSort(nums, q + 1, end);
    }
}

void sort(std::vector<int> &nums)
{
    quickSort(nums, 0, nums.size() - 1);
}

}
