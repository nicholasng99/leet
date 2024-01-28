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
        double maxAverage = -numeric_limits<double>::max();
        for (int i = 0; i < nums.size(); ++i)
        {
            windowSum += nums[i];
            if (i >= k)
                windowSum -= nums[i - k];
            if (i >= k - 1)
                maxAverage = std::max(maxAverage, windowSum / k);
        }
        return maxAverage;
    }
};
// @lc code=end
