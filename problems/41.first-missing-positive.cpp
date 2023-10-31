/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <set>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::set<int> numbersSet;
        for (int i = 0; i < nums.size() + 1; ++i)
            numbersSet.insert(i + 1);
        for (auto& num : nums)
                numbersSet.erase(num);
        return *numbersSet.begin();
    }
};
// @lc code=end

