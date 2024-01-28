/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result;

        // using monotonic stack
        stack<pair<int, int>> history;
        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            int days = 0;

            while (!history.empty() && history.top().first <= temperatures[i])
            {
                days += history.top().second;
                history.pop();
            }
            if (!history.empty() && history.top().first > temperatures[i])
                days++;
            else
                days = 0;
            history.push({ temperatures[i], days });
            result.push_back(days);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
