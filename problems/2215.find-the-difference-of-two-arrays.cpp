/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    // my initial attempt
    // vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    //     vector<vector<int>> result;
    //     set<int> a,b,temp;
    //     for (auto& num : nums1)
    //         a.insert(num);
    //     for (auto& num : nums2)
    //         b.insert(num);
    //     set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(temp, temp.begin()));
    //     result.push_back(vector<int>(temp.begin(), temp.end()));
    //     temp.clear();
    //     set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(temp, temp.begin()));
    //     result.push_back(vector<int>(temp.begin(), temp.end()));
    //     return result;
    // }
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> result(2, vector<int>());
        unordered_set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
        for (auto &num : a)
            if (b.count(num) < 1)
                result[0].push_back(num);
        for (auto &num : b)
            if (a.count(num) < 1)
                result[1].push_back(num);
        return result;
    }
};
// @lc code=end
