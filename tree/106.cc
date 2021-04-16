/*106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：*/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return reverse(inorder,postorder,postorder.size()-1,0,inorder.size()-1);
   
    }

     TreeNode* reverse(vector<int>& in,vector<int>& post,int i,int left,int right)
    {
        if(left > right) return nullptr;
        int j = 0;
        for(int k = left; k<=right; ++k)
        {
            if(in[k] == post[i]) j = k;
        }
        TreeNode* left_node = reverse(in,post,i-right+j-1,left,j-1);
        TreeNode* right_node = reverse(in,post,i-1,j+1,right);
        return new TreeNode(in[j],left_node,right_node);
    }
};