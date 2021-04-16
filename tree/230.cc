/*230. 二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

 

示例 1：


输入：root = [3,1,4,null,2], k = 1
输出：1
示例 2：


输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int left = count(root -> left);
        if(k - left == 1) return root -> val;
        if(k - left > 0) return kthSmallest(root -> right, k - left - 1);
        else return kthSmallest(root -> left, k);
    }
    int count(TreeNode* node)
    {
        if(!node) return 0;
        return count(node -> left) + count(node -> right) + 1;
    }
};