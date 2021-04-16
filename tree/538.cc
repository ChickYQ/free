/*
538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

 

示例 1：



输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
示例 2：

输入：root = [0,null,1]
输出：[1,null,1]
示例 3：

输入：root = [1,0,2]
输出：[3,3,2]
示例 4：

输入：root = [3,2,4,1]
输出：[7,9,4,10]
*/


#include<iostream>
#include<vector>
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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        int num = root -> val;
        root -> val = count(root -> right) + num;
        reverse(root,num);
        return root;
    }
    int count(TreeNode* node)
    {
        if(!node) return 0;
        return node -> val + count(node -> left) + count(node -> right);
    }
    void reverse(TreeNode* node, int num)
    {
        if(node -> left)
        {
        int left = node -> left -> val;
        node-> left -> val = node -> val + count(node -> left -> right) + left;
        reverse(node-> left,left);
        }
        if(node -> right)
        {
        int right = node -> right -> val;
        node -> right -> val = node -> val - num - count(node -> right -> left);
        reverse(node -> right,right);
        }
    }
};