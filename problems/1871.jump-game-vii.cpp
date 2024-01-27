/*
 * @lc app=leetcode id=1871 lang=cpp
 *
 * [1871] Jump Game VII
 */

// @lc code=start
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    enum State : int
    {
        UNKOWN = -1,
        UNREACHABLE = 0,
        REACHABLE = 1
    };

    std::vector<State> reachable;
    int minJ, maxJ;

    bool search(const std::string& space, const int& index)
    {
        if (index >= space.size() || space.at(index) == '1')
            return false;
        if (index == space.size() - 1)
            return true;
        if (reachable.at(index) == State::UNKOWN)
        {
            reachable[index] = State::UNREACHABLE;
            for (int i = maxJ; i >= minJ; --i)
                if (search(space, index + i))
                {
                    reachable[index] = State::REACHABLE;
                    return true;
                }
        }
        return reachable.at(index);
    }

    bool canReach(std::string s, int minJump, int maxJump)
    {
        if (s.back() == '1')
            return false;
        int oneCounter = 0;
        for (auto& c : s)
        {
            oneCounter = c == '1' ? oneCounter + 1 : 0;
            if (oneCounter >= maxJump)
                return false;
        }
        reachable = std::vector<State>(s.size(), State::UNKOWN);
        minJ = minJump;
        maxJ = maxJump;
        return search(s, 0);
    }
};
// @lc code=end
