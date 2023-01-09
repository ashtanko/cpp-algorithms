#include <iostream>
#include <vector>

// https://leetcode.com/problems/two-sum/
class TwoSum {
public:
    static std::vector<int> solve(std::vector<int> &nums, int target) {
        std::vector<int> index;
        u_long size = nums.size();
        for (int i = 0; i < size; i++) {
            int k = target - nums[i];
            for (int j = i + 1; j < size; j++) {
                if (nums[j] == k) {
                    index.push_back(i);
                    index.push_back(j);
                    break;
                }
            }
            if (index.size() == 2) {
                break;
            }
        }
        return index;
    }
};

int main() {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    std::vector<int> expected;
    expected.push_back(0);
    expected.push_back(1);
    int target = 9;
    for (int n: nums) {
        std::cout << n << "\n";
    }
    std::vector<int> result = TwoSum::solve(nums, target);
    std::cout << "result:\n";
    for (int i: result) {
        std::cout << i << " ";
    }
    assert(result == expected);
    return 0;
}
