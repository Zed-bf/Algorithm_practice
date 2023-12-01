#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==0||n==0){
            return 0;
        }
        //定义dp[i][j]表示从00 到ij的最小路径
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0] = grid[0][0];
        // 初始化边界
        for(int i = 1;i<m ;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        for(int j = 1;j<n ;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        // dp[i][j] = min(dp[i-1][j],dp[i][j-1])+ grid[i][j];
        for(int i =1;i<m;i++){
            for(int j =1; j<n;j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+ grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};