
/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return reverse(preorder,inorder,0,0,inorder.size()-1);
    }

    TreeNode* reverse(vector<int>& pre,vector<int>& in,int i,int left,int right)
    {
        if(left > right) return nullptr;
        int j = 0;
        for(int k = left; k<=right; ++k)
        {
            if(in[k] == pre[i]) j = k;
        }
        TreeNode* left_node = reverse(pre,in,i+1,left,j-1);
        TreeNode* right_node = reverse(pre,in,i + j - left + 1,j+1,right);
        return new TreeNode(in[j],left_node,right_node);
    }
};