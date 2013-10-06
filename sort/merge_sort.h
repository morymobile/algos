#include <algorithm>
#include <vector>
#include <iostream>


namespace MergeSort {

void merge(std::vector<int> &nums, int i, int j, int k)
{
    std::vector<int> l1, l2;
    std::copy(nums.begin()+i, nums.begin()+j+1, std::back_inserter(l1));
    std::copy(nums.begin()+j+1, nums.begin()+k+1, std::back_inserter(l2));
    int i1 = 0, i2 = 0;
    for (int a = i; a < k+1; ++a) {
        if (i1 < l1.size() && i2 < l2.size()) {
            if (l1[i1] <= l2[i2]) {
                nums[a] = l1[i1++];
            } else {
                nums[a] = l2[i2++];
            }
        } else {
            if (i1 < l1.size())
                nums[a] = l1[i1++];
            else if (i2 < l2.size())
                nums[a] = l2[i2++];
        }
    }
}

/*
void merge(std::vector<int> &nums, int i, int j, int k)
{
    int m = j+1;
    for (int a = m; a <= k; ++a) {
        for (int b = a-1; b >= i; --b) {
            if (nums[b+1] < nums[b]) {
                std::swap(nums[b+1], nums[b]);
            } else {
                break;
            }
        }
    }
}
*/

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
