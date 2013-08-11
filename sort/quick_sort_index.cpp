#include <vector>
#include <iostream>
#include <algorithm>

int sortPartition(std::vector<int> &numbers, int start, int end, std::vector<int> &indices)
{
    const int x = numbers[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (numbers[j] <= x) {
            i = i+1;
            if (i != j) {
                const int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
                const int tmpIndex = indices[i];
                indices[i] = indices[j];
                indices[j] = tmpIndex;
            }
        }
    }
    i = i+1;
    if (i != end) {
        const int tmp = numbers[i];
        numbers[i] = numbers[end];
        numbers[end] = tmp;
        const int tmpIndex = indices[i];
        indices[i] = indices[end];
        indices[end] = tmpIndex;
    }
    return i;
}

void quickSort(std::vector<int> &numbers, int start, int end, std::vector<int> &indices)
{
    if (start < end) {
        const int q = sortPartition(numbers, start, end, indices);
        quickSort(numbers, start, q - 1, indices);
        quickSort(numbers, q + 1, end, indices);
    }
}

//void quickSort(std::vector<int> &numbers)
//{
//quickSort(numbers, 0, numbers.size() - 1);
//}

void verify(const std::vector<int> &numbers)
{
    std::cout << "Result:" << std::endl;
    std::vector<int>::const_iterator prev = numbers.end();
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << "  ";
        if (it != numbers.begin()) {
            if (*it < *prev) {
                std::cout << std::endl << "Error:" << *it << " < " << *prev << std::endl;

            }
        }
        prev = it;
    }
    std::cout << std::endl;
}

void quickSortIndex(std::vector<int> &numbers, std::vector<int> &indices)
{
    const int size = numbers.size();
    for (int i = 0; i < size; ++i) {
        indices.push_back(i);
    }
    quickSort(numbers, 0, size - 1, indices);
}

//void sortVerify(std::vector<int> &numbers)
//{
//quickSort(numbers);
//verify(numbers);
//}

void sortIndexVerify(std::vector<int> &numbers)
{
    std::vector<int> indices;
    quickSortIndex(numbers, indices);
    verify(numbers);
    for (std::vector<int>::const_iterator it = indices.begin(); it != indices.end(); ++it)
    {
        std::cout << numbers[*it] << "  ";
    }
}

int main()
{
    std::vector<int> numbers;
    //numbers.push_back(3);
    //numbers.push_back(1);
    //numbers.push_back(7);
    //numbers.push_back(-8);
    //numbers.push_back(4);
    //numbers.push_back(6);
    //numbers.push_back(3);
    //sortVerify(numbers);
    //
    //numbers.clear();
    numbers.push_back(150);
    numbers.push_back(24);
    numbers.push_back(79);
    numbers.push_back(50);
    numbers.push_back(88);
    numbers.push_back(345);
    numbers.push_back(3);
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        std::cout << *it << "  ";
    }
    sortIndexVerify(numbers);

    return -1;
}
