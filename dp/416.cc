/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
      //背包问题, dp[i][j]表示背包容量为j时，从nums[0--i]中是否能选取一个数使得刚好把背包填满
        int target = 0;
        for(int i = 0; i<nums.size(); ++i) target += nums[i];
        //奇数不可分
        if(target % 2 !=0) return false;
        bool dp[200][10001];
        //背包为0，一定能填满
        for(int i = 0; i<200; ++i) dp[i][0] = true;
        for(int i = 0; i<10001;++i) dp[0][i] = (nums[0] == i);
        dp[0][0] = true;

        for(int i = 1; i<nums.size(); ++i)
        {
            for(int j = 0; j <=target/2;++j)
            {
                //不选nums[i],只选nums[i],选nums[i]，三种情况任一为true，则dp[i][j]为true
                dp[i][j] = dp[i-1][j] || (nums[i] == j) || (nums[i]<j && dp[i-1][j-nums[i]]);
            }
            
        }
        return dp[nums.size() - 1][target/2];
    }
};