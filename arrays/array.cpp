#include "../utils/common.hpp"

int randomAccess(const int *nums, int size) {
    int randomIndex = rand() % size;
    int randomNum = nums[randomIndex];
    return randomNum;
}

int main() {
    int size = 5;
    int *arr = new int[size];

    cout << "arr = ";
    printArray(arr, size);

    int *nums = new int[size]{1, 3, 2, 5, 4};
    cout << "nums = ";
    printArray(nums, size);

    int randomNum = randomAccess(nums, size);
    cout << "Get a random element from nums:  " << randomNum << endl;
}
