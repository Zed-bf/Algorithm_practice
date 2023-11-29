#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string sr(s.rbegin(),s.rend());
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for (int i=1;i<n+1;i++){
            char c1 = s[i-1];
            for(int j =1;j<n+1;j++){
                char c2 = sr[j-1];
                if(c1==c2){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
        }
        return dp[n][n];
    }
};

/* 
leetcode 516 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：

输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。 */