/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    bool possible(vector<int>& piles, const int& k, const int& h)
    {
        uint64_t sum = 0;
        for (auto& pile : piles)
        {
            sum += pile / k;
            if (pile % k > 0)
                ++sum;
        }
        return sum <= h;
    }

    int binarySearch(vector<int>& piles, const int& min, const int& max, const int& h)
    {
        if (min >= max)
            return possible(piles, min, h) ? min : min + 1;
        const int MID = (max + min) / 2;
        if (possible(piles, MID, h))
            return binarySearch(piles, min, MID - 1, h);
        return binarySearch(piles, MID + 1, max, h);
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        sort(piles.begin(), piles.end());
        int max = piles.back();
        return binarySearch(piles, 1, max, h);
    }
};
// @lc code=end
