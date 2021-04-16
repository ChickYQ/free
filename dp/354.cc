/*
354. 俄罗斯套娃信封问题
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。

 
示例 1：

输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
示例 2：

输入：envelopes = [[1,1],[1,1],[1,1]]
输出：1
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    //先内部升序排序，再外部排序
    bool cmp(vector <int> & a, vector <int> & b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        else
            return a[1] < b[1];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

      if(envelopes.size() <= 1) return 1;
      sort(envelopes.begin(),envelopes.end(),cmp);
      int result = 1;
      int dp[5001];
      for(int i = 0; i< 5001; ++i) dp[i] = 1;
      //求最长递增子序列
      for(int i = 0; i< envelopes.size(); ++i)
      {
        for(int j = 0; j<i; ++j)
        {
          //内外都必须满足严格递增
          if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
          {
            dp[i] = max(dp[i],dp[j] + 1);
          }
          result = max(result,dp[i]);
        }
      }
    return result;
    }
};

int main()
{
  Solution solution;
  vector<vector<int>> v1 = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
  cout << solution.maxEnvelopes(v1) << endl;

  return 0;
}