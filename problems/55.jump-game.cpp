/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return true;
        int maxIndex = 0;
        for (int i = 0; i <= maxIndex; ++i)
        {
            maxIndex = std::max(nums.at(i) + i, maxIndex);
            std::cout << std::to_string(maxIndex) << std::endl;
            if (maxIndex >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
