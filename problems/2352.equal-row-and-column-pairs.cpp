/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
#include <iostream>
#include <map>
#include <vector>

using namespace std;
class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>, int> rowCounter, colCounter;
        for (int i = 0; i < grid.size(); ++i)
        {
            rowCounter[grid[i]]++;
            vector<int> column;
            for (int j = 0; j < grid.size(); ++j)
                column.push_back(grid[j][i]);
            colCounter[column]++;
        }
        int totalPairs = 0;
        for (auto& pair : rowCounter)
        {
            if (colCounter.count(pair.first) > 0)
                totalPairs += pair.second * colCounter[pair.first];
        }
        return totalPairs;
    }
};
// @lc code=end
