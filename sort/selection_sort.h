#include <algorithm>
#include <vector>
#include <iostream>


namespace SelectionSort {

void sort(std::vector<int> &nums)
{
    const int size = nums.size();
    for (int i = 0; i < size; ++i) {
        int k = i;
        for (int j = i+1; j < size; ++j) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        if (i != k) {
            std::swap(nums[i], nums[k]);
        }
    }
}

}
