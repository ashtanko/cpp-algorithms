#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/two-sum/
vector<int> twoSum(vector<int> &numbers, int target) {
    // https://en.cppreference.com/w/cpp/container/unordered_map
    unordered_map<int, int> hash;

    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

        if (hash.find(numberToFind) != hash.end())
            return {hash[numberToFind], i};

        hash[numbers[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> expected = {0, 1};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    assert(result == expected);
    return 0;
}
