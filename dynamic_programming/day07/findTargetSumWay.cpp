#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;

//分为 pos 和 neg  sum = pos+neg   target = pos -neg   neg =（sum-target)/2
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        //计算数组和
        for(int num:nums){
            sum = sum+ num;
        }
        int diff = sum -target; 
        // 如果差小于0或者不是偶数则没有方法
        if(diff<0||diff%2!=0){
            return 0;
        }
        int n = nums.size();
        int neg = diff/2;
        vector<vector<int>> dp(n+1,vector<int>(neg+1));
        dp[0][0] = 1;
        for(int i= 1;i<n+1;i++){
            int num = nums[i-1];
            for(int j =0;j<neg+1;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=num){
                    dp[i][j]+=dp[i-1][j-num];
                }
            }
        }
        return dp[n][neg];

    }
};

/* leetcode 494 目标和
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
示例 2：

输入：nums = [1], target = 1
输出：1 */
 