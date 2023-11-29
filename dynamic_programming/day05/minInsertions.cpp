#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
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
        return n-dp[n][n];
    }
};


/* 
leetcode 1312 让字符串成为回文串的最少插入次数
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。

 

示例 1：

输入：s = "zzazz"
输出：0
解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
示例 2：

输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
示例 3：

输入：s = "leetcode"
输出：5
解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 

提示：

1 <= s.length <= 500
s 中所有字符都是小写字母。 */