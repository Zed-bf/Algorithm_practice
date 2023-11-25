// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 你可以认为每种硬币的数量是无限的。
// 示例 1：
// 输入：coins = [1, 2, 5], amount = 11
// 输出：3 
// 解释：11 = 5 + 5 + 1
// 示例 2：
// 输入：coins = [2], amount = 3
// 输出：-1
// 示例 3：
// 输入：coins = [1], amount = 0
// 输出：0
#include<iostream>
#include<vector>
using namespace std;
class Solution{
private:
    vector<int> memo;
    int dp(vector<int> & coins,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(memo[amount]!=-999){
            return memo[amount];
        }
        int ans = INT_MAX;
        for( int coin:coins){
            int sub_problem = dp(coins,amount-coin);
            if (sub_problem == -1) continue;
            ans = min(ans,sub_problem+1);
        }
        memo[amount] = ans==INT_MAX?-1:ans;
        return memo[amount];

    }
public:
    int coinChange(vector<int> & coins,int amount){
        memo = vector<int>(amount+1,-999);
        return  dp(coins,amount);
    }
};

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    Solution way;
    int ans;
    ans = way.coinChange(coins,amount);
    cout<<ans<<endl;
    return 0;
}