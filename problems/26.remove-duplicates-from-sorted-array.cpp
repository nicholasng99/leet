/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int unique = 0;
        for (auto& num : nums)
            if (std::find(nums.begin(), nums.begin() + unique, num) == nums.begin() + unique)
                nums[unique++] = num;
        return unique;
    }
};
// @lc code=end
