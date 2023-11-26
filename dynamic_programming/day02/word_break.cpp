#include<iostream>
#include<unordered_set>
#include<vector>
// #include<set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = s.size();
        //在字符串加一个' ',方便计算
        s = ' '+ s;
        vector<bool> dp(n+1);
        dp[0] =true;
        for(int i =0 ;i <= n;i++){
            for(int j=i;j>0;j--){
                if(dp[j-1]&&st.count(s.substr(j,i-j+1))){
                    dp[i]=true;
                    break;
                }
            }
        }

    return dp[n];
    }
};