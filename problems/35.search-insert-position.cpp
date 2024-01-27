/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, const int& min, const int& max, const int& target)
    {
        if (nums.empty())
            return 0;
        if (min >= nums.size())
            return nums.size();
        if (min >= max)
            return target > nums[min] ? min + 1 : min;
        const int MID = (max - min) / 2 + min;
        if (target == nums[MID])
            return MID;
        if (target > nums[MID])
            return binarySearch(nums, MID + 1, max, target);
        return binarySearch(nums, min, MID - 1, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size(), target);
    }
};
// @lc code=end

