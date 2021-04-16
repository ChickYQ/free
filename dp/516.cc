/*
516. 最长回文子序列
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

 

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

 

提示：

1 <= s.length <= 1000
s 只包含小写英文字母
通过次数43,717提交次数71,968
*/

/*
解法：dp[i][j]代表子串s[i--j]的最大回文序列
*/
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int dp[1001][1001];
        //由后向前推导
        for(int i = s.size(); i>0; --i)
        {
          //右侧索引必须大于左侧
            for(int j = i; j<=s.size(); ++j)
            {
                if(i == j) dp[i][j] = 1;//单个字母为1
                else if(j - i == 1) dp[i][j] = (s[i - 1] == s[j - 1] ? 2 : 1);//相邻字母相等为2
                else{
                  //字符相等，回文长度加2
                    if(s[i - 1] == s[j - 1])
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }else
                    {
                      //不等取最大长度
                        dp[i][j] = max(dp[i + 1][j],dp[i][j-1]);
                    }
                }
            }
        }
        //返回s[1---n]的最大回文子串
        return dp[1][s.size()];
    }
};