/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <iostream>
#include <string>
#include <set>

using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double windowSum = 0;
        for (int i = 0; i < k; ++i)
            windowSum += nums[i];
        double maxAverage = windowSum / k;
        for (int i = k; i < nums.size(); ++i)
        {
            windowSum += nums[i];
            windowSum -= nums[i - k];
            maxAverage = max(maxAverage, windowSum / k);
        }
        return maxAverage;
    }
};
// @lc code=end
