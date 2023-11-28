#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int res = nums[0];
        dp[0] =nums[0];
        for (int i=1;i<n;i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            res = max(res,dp[i]);
        }
        return res;
    }
};