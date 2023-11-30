#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int maxNum = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            maxNum = max(maxNum,nums[i]);
            sum = sum + nums[i];
        }
        //个数小于2划分不了
        if(n<2){
            return false;
        }
        // 如果和不是偶数必然划分不了
        if(sum%2!=0){
            return false;
        }
        int target = sum/2;
        if(maxNum>target){
            return false;
        }
        // 定义dp[i][j]  表示下表0~i能不能取到一些和为j
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        //边界问题；当目标值为0时可以不取；所以都为true
        for (int i =0 ; i< n;i++){
            dp[i][0] = true;
        }
        //当只可以取0时；只可以取num[0];所以 dp[0][nums[0]] = true
        dp[0][nums[0]] = true;
        for(int i=1;i < n;i++){
            int num = nums[i];
            for(int j=1;j<target+1;j++){
                //当num大于j时；这个肯定不加入；看之前的能不能划分
                if(num>j){
                    dp[i][j] = dp[i-1][j];
                }
                //不大于时可以加入也可以不加入  所以用 |
                else{
                    dp[i][j] =dp[i-1][j] | dp[i-1][j-num];
                }
            }
        }
        return dp[n-1][target];
    }
};

/* 
leetcode 416 分割等和子集
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
1 <= nums[i] <= 100 */