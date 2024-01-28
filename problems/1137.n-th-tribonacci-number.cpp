/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
#include <iostream>
#include <map>

using namespace std;
class Solution
{
public:
    map<int, int> known;
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (known.count(n) > 0)
            return known.at(n);
        known.insert({ n - 1, tribonacci(n - 1) });
        known.insert({ n - 2, tribonacci(n - 2) });
        known.insert({ n - 3, tribonacci(n - 3) });
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
// @lc code=end
