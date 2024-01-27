/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void insertAndPush(vector<int>& array, const int& item, const int& index)
    {
        std::cout << "Insert " << item << " at " << index << std::endl;
        for (int i = array.size() - 1; i > index; --i)
            array[i] = array[i - 1];
        array[index] = item;
    }

    int binarySearch(vector<int>& array, const int& min, const int& max, const int& item)
    {
        if (min >= max)
            return item > array[min] ? min + 1 : min;
        const int MID = (max - min) / 2 + min;
        if (item == array[MID])
            return MID + 1;
        if (item > array[MID])
            return binarySearch(array, MID + 1, max, item);
        return binarySearch(array, min, MID - 1, item);
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            auto index = binarySearch(nums1, 0, m - 1 + i, nums2[i]);
            insertAndPush(nums1, nums2[i], index);
            std::cout << "insert " << nums2[i] << " at " << index << std::endl;
        }
    }
};
// @lc code=end
