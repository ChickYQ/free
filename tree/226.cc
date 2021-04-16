#include<iostream>
/*
226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        reverse(root);
        return root;
    }
    void reverse(TreeNode* node)
    {
        if(!node -> left && !node -> right) return;
        if(node -> left)
        {
            if(node -> right)
            {
                swap(node -> left, node -> right);
                reverse(node -> left);
                reverse(node -> right);
            }else
            {
                node -> right = node -> left;
                node -> left = nullptr;
                reverse(node -> right);
            }
        }else
        {
            node -> left = node -> right;
            node -> right = nullptr;
            reverse(node -> left);
        }
    }
};