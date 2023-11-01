/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        const auto size = nums.size();
        std::vector<bool> numbers(size, false);
        for (auto& num : nums) {
            if (num < 1 || num > size)
                continue;
            numbers[num - 1] = true;
        }
        for (int i=0; i<size; ++i)
            if (!numbers[i])
                return i + 1;
        return size + 1;
    }
};
// @lc code=end

