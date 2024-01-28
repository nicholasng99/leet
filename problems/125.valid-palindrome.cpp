/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <iostream>
#include <string>
#include <set>

using namespace std;
class Solution
{
public:
    std::optional<char> toValidLower(const char &c)
    {
        if (c >= 'a' && c <= 'z')
            return c;
        if (c >= 'A' && c <= 'Z')
            return c - ('A' - 'a');
        if (c >= '0' && c <= '9')
            return c;
        return std::nullopt;
    }

    bool isPalindrome(string s)
    {
        string validString;
        for (auto &c : s)
        {
            auto lower = toValidLower(c);
            if (lower.has_value())
                validString += lower.value();
        }
        for (int i = 0; i < validString.length() / 2; ++i)
            if (validString[i] != validString[validString.length() - 1 - i])
                return false;
        return true;
    }
};
// @lc code=end
