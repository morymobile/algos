#include <algorithm>
#include <vector>
#include <iostream>


namespace BubbleSort {

void sort(std::vector<int> &nums)
{
    const size_t size = nums.size();
    for (size_t i = size-1; i > 0; --i) {
        /*std::cout << "i: " << i << std::endl;*/
        for (size_t j = 0; j < i; ++j) {
            /*std::cout << "j: " << j << std::endl;*/
            if (nums[j] > nums[j+1]) {
                /*std::cout << "swap: " << j << j+1 << std::endl;*/
                std::swap(nums[j], nums[j+1]);
            }
        }
    }
}

}
