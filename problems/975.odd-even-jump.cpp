/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:

    int nextIndex(const vector<int>& arr, int index, bool odd) {
        int limit = odd ? numeric_limits<int>::max() : numeric_limits<int>::min();
        int next = -1;
        for (int i=index+1; i<arr.size(); ++i)
        {
            bool condition = odd ? 
            arr[i] >= arr[index] && arr[i] < limit:  
            arr[i] <= arr[index] && arr[i] > limit;
            if (condition)
            {
                limit = arr[i];
                next = i;
            }
        }
        return next;
    }

    bool jumpToEnd(const vector<int>& arr, int index, bool odd) {
        // cout << "\tIndex: " << index << endl;
        if (index >= arr.size() - 1)
            return true;
        int next = nextIndex(arr, index, odd);
        // cout << "\tNext: " << next << endl;
        if (next < 0)
            return false;
        return jumpToEnd(arr, next, !odd);
    }

    int oddEvenJumps(vector<int>& arr) {
        int count = 0;
        for (int i=0; i<arr.size(); ++i)
        {
            // cout << "Start: " << i << endl;
            if (jumpToEnd(arr, i, true))
            {
                // cout << "Reached end " << endl;
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

