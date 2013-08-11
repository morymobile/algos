#include <algorithm>
#include <vector>
#include <iostream>


namespace MergeSort {

void merge(std::vector<int> &nums, int i, int j, int k)
{
    int s1 = i, e1 = j, s2 = j+1, e2 = k, a = 0;
    std::vector<int> tmp(k-i+1, 0);
    while (s1 <= e1 && s2 <= e2) {
        if (nums[s1] <= nums[s2]) {
            nums[a++] = nums[s1++];
        } else {
            nums[a++] = nums[s2++];
        }
    }
    if (s1 < e1) {
        s2 = s1;
        e2 = e1;
    }
    while (s2 <= e2) {
        tmp[a++] = nums[s2++];
    }

    a = 0;
    for (int b = i; b <= k; ++b) {
        nums[b] == tmp[a++];
    }
}

void merge_sort(std::vector<int> &nums, int p, int q)
{
    if (p < q) {
        const int mid = (p+q)/2;
        merge_sort(nums, p, mid);
        merge_sort(nums, mid+1, q);
        merge(nums, p, mid, q);
    }
}

void sort(std::vector<int> &nums)
{
    const int size = nums.size();
    merge_sort(nums, 0, size-1);
}

}
