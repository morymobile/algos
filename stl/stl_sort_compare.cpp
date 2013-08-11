#include <algorithm>
#include <string>
#include <vector>
#include <iostream>


using namespace std;


bool comparator(const int &a, const int&b) {
    return a < b;
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(-1);
    nums.push_back(-4);

    sort(nums.begin(), nums.end(), comparator);
    cout << "sorted: " << is_sorted(nums.begin(), nums.end());
}
