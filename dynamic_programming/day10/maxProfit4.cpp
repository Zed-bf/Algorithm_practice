#include<iostream>
// #include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        int buy[k];
        int sell[k];
        for(int i=0;i<k;i++){
            buy[i] = -prices[0];
            sell[i] = 0;
        }
        for(int i =1;i<n;i++){
            buy[0] = max(buy[0],-prices[i]);
            sell[0] = max(sell[0],buy[0] + prices[i]);
            for(int j=1;j<k;j++){
                buy[j] = max(buy[j],sell[j-1]-prices[i]);
                sell[j] = max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k-1];

    }
};
/* leetcode 188 买卖股票 4
给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。 */
 