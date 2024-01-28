/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        int depthLeft = 1, depthRight = 1;
        if (root->left) {
            depthLeft += maxDepth(root->left);
        }
        if (root->right) {
            depthRight += maxDepth(root->right);
        }
        return max(depthLeft, depthRight);
    }
};
// @lc code=end
