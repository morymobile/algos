#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "../common/string_util.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"


bool isSorted(const std::vector<int> &nums)
{
    if (nums.empty())
        return true;

    for (std::vector<int>::const_iterator it = nums.begin(), prev = it++;
        it != nums.end(); ++it) {
        if (*prev > *it) {
            return false;
        }
        prev = it;
    }
    return true;
}

typedef void (*SortDg)(std::vector<int> &);

void sortAndVerify(std::vector<int> nums, SortDg dg, const std::string &name)
{
    dg(nums);
    if (!isSorted(nums)) {
        std::cout << name << " failed: " << StringUtil::join(nums, ',') << std::endl;
    }
}

void str2IntVector(const std::string &str, std::vector<int> &nums) {
    std::vector<std::string> items;
    StringUtil::split(str, items, ',');
    for (size_t i = 0; i < items.size(); ++i) {
        nums.push_back(atoi(items[i].c_str()));
    }
}

void sortAndVerifyAll(const std::string &s)
{
    std::vector<int> nums;
    str2IntVector(s, nums);

    //TODO: Add new sort algo here
    sortAndVerify(nums, &QuickSort::sort, "QuickSort");
    sortAndVerify(nums, &BubbleSort::sort, "BubbleSort");
    sortAndVerify(nums, &InsertionSort::sort, "InsertionSort");
    sortAndVerify(nums, &SelectionSort::sort, "SelectionSort");
    sortAndVerify(nums, &MergeSort::sort, "MergeSort");
}

int main()
{
    sortAndVerifyAll("1, 2, 3, 4, 5, 6, 7, 9");
    sortAndVerifyAll("1, 2, 3, 4, 5, 6, 7, 9, 10");
    sortAndVerifyAll("-1, -2, -3, -4, -5, -6, -7, -9");
    sortAndVerifyAll("-1, -2, -3, -4, -5, -6, -7, -9, -10");
    sortAndVerifyAll("-1, 5, 3, -8, 7, 2, 9, 4");
    sortAndVerifyAll("-1, 5, 3, -8, 7, 2, 9, 4, 3");
    sortAndVerifyAll("1");
    sortAndVerifyAll("1,2");
    sortAndVerifyAll("2,1");
    sortAndVerifyAll("2,1,3");
    sortAndVerifyAll("3,1,2");
    sortAndVerifyAll("");
    return 0;
}
