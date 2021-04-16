/*
518. 零钱兑换 II
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        //完全背包问题，dp[i][j]为只用i之前的数填满j的组合数
        vector<std::vector<int>> dp(coins.size() + 1,vector<int>(amount + 1,0));

      //不用任何数则为0
       for(int i = 0; i<=amount;++i) dp[0][i] = 0;
       //背包大小为0，任意数填充方式都为1
       for(int i = 0; i<=coins.size();++i) dp[i][0] = 1;
       for(int i = 1; i<=coins.size();++i)
       {
           for(int j = 1;j<=amount;++j)
           {
               if(j - coins[i - 1] >= 0)
               {
                   //填充方式等于不用nums[j]和用nums[j]的个数之和
                   dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
               }else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
        return dp[coins.size()][amount];

    }
};