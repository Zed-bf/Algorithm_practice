#include<iostream>
#include<vector>
using namespace std;
//leetcode 932  最小下降路径和
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size();
        //定义备忘录
        vector<vector<int>> memo(n,vector<int>(n,66666));
        for(int j =0;j<matrix[0].size();j++){
            res = min(res,dp(matrix,memo,n-1,j));
        }
        return res;
    }

    int dp(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j){
        //索引检查
        if( i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()){
            return 99999;
        }
        //是否已经计算过
        if(memo[i][j]!=66666){
            return memo[i][j];
        }
        //注意初始化i=0时
        if(i==0){
            return matrix[i][j];
        }
        memo[i][j] = matrix[i][j] + min_3(
            dp(matrix,memo,i-1,j),
            dp(matrix,memo,i-1,j-1),
            dp(matrix,memo,i-1,j+1));

        return memo[i][j];
    }
    int min_3(int a,int b,int c){
        return min(a,min(b,c));
    }

};
// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和。
// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
// 在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）
// 。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。