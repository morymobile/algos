#include <algorithm>
#include <vector>
#include <iostream>


namespace InsertionSort {

void sort(std::vector<int> &nums)
{
    const int size = nums.size();
    for (int i = 1; i < size; ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
            } else {
                break;
            }
        }
    }
}

}
