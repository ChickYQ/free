/*
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
       int dp[501][501];
       //一定要初始化为-1！！！！！！！！！！！！！
        for(int i = 0; i<501; ++i)
    {
        for(int j = 0; j< 501; ++j)
        dp[i][j] = -1;
    }
       return replace(dp,word1.size(),word2.size(),word1,word2);
    }
   
   //dp[i][j]代表子串s1[0--i]变成子串s2[0---j]所需最小步数
    int replace(int dp[501][501],int i,int j,string &s1,string &s2)
    {
        int result;
        //剪枝
        if(dp[i][j]>=0) return dp[i][j];
        //其中一个子串变为空，需将另一子串也变为空
        if(i == 0 || j == 0) result = i + j;
        //两字符相等，不需要操作，同时缩短子串长度
        else if(s1[i-1] == s2[j-1]) 
        {
            result = replace(dp,i-1,j-1,s1,s2);
        }else
        {
          //递归计算插入dp[i][j-1],删除dp[i-1][j],替换dp[i-1][j-1]中代价最小的操作
            int temp = min(replace(dp,i-1,j,s1,s2) ,replace(dp,i - 1,j - 1,s1,s2)); 
            result = min(temp,replace(dp,i,j-1,s1,s2)) + 1;
        }
        dp[i][j] = result;
        return result;
    }
};