/*
652. 寻找重复的子树
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。
*/

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        map<string,int> same_map;
        reverse(result,same_map,root);
        return result;
    }

    string reverse(vector<TreeNode*>& result,map<string,int>& same_map,TreeNode* node)
    {
        if(!node) return " ";
        string s = "";
        s += node -> val;
        s += reverse(result,same_map,node -> left);
        s += reverse(result, same_map, node -> right);
        if(same_map[s] >= 1)
        { 
        result.push_back(node);
        same_map[s] = -1;
        }else if(same_map[s] == 0)
        {
            same_map[s] = 1;
        }

        return s;

    }
};