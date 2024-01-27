/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int index = 0;
        for (auto& num : nums)
            if (num != val)
                nums[index++] = num;
        return index;
    }
};
// @lc code=end
