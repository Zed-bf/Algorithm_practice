#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;
class Solution {
private:
    // 备忘录
    vector<vector<int>> memo;
    int dp(string s1, int i, string s2, int j) {
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;
        // 查备忘录，避免重叠子问题
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        // 状态转移，结果存入备忘录
        if (s1[i] == s2[j]) {
            memo[i][j] = dp(s1, i - 1, s2, j - 1);
        } else {
            memo[i][j] = min_3(
                dp(s1, i, s2, j - 1) + 1,
                dp(s1, i - 1, s2, j) + 1,
                dp(s1, i - 1, s2, j - 1) + 1
            );
        }
        return memo[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // 备忘录初始化为特殊值，代表还未计算
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return dp(word1, m - 1, word2, n - 1);
    }
    int min_3(int a, int b, int c) {
        return min(a, min(b, c));
    }
};