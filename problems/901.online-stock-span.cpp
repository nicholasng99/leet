/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <iostream>
#include <stack>

using namespace std;
class StockSpanner
{
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!history.empty() && history.top().first <= price)
        {
            span += history.top().second;
            history.pop();
        }
        history.push({ price, span });
        return span;
    }

private:
    stack<pair<int, int>> history;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
