// https://leetcode.com/problems/coin-change-2/

// dp solution
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i< coins.size(); i++){
            for (int j = 0; j<amount+1; j++){
                if(coins[i]+j>amount) break;
                
                dp[coins[i]+j] += dp[j];
            }
        }

        return dp[amount];
    }
};
