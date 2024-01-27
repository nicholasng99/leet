/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        set<int> twice;
        int unique = 0;
        for (auto& num : nums)
            if (std::find(nums.begin(), nums.begin() + unique, num) == nums.begin() + unique)
                nums[unique++] = num;
            else if (twice.count(num) < 1)
                twice.insert(nums[unique++] = num);
        return unique;
    }
};
// @lc code=end

