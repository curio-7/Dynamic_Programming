class Solution {
public:

    int tab(vector<int>&prices,int n,int k){
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        //loops
        for(int i=n-1;i>=0;i--){
            for(int ts = 2*k-1;ts>=0;ts--){
                int profit = 0;
                if(ts%2==0){
                    //either u can buy it or u cant
                    profit = max(-prices[i]+dp[i+1][ts+1],
                              0 + dp[i+1][ts]);
                }
                else{
                    //either u can sell or u cant
                    profit =  max(prices[i] + dp[i+1][ts+1],
                              0 + dp[i+1][ts]);

                }
                dp[i][ts] = profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return tab(prices,n,k);
    }
};