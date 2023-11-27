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

/* 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

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
exection -> execution (插入 'u') */