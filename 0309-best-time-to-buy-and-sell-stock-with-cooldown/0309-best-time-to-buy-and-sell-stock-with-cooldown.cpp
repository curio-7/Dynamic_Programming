class Solution {
public:
    int tab(vector<int>&prices,int n){
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //base case
        dp[n][1] = dp[n][0] = 0;
        //loops
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int profit = 0;
                if(j){
                    //we can either buy or not buy
                    profit = max(-prices[i] + dp[i+1][0],0 + dp[i+1][1]);
                }
                if(!j){
                    //i.e you can sell or you can not sell
                    profit = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
            
            
        }
        return dp[0][1];
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return tab(prices,n);
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        //base case
        dp[n][1] = dp[n][0] = 0;
        //loops
        for(int i=n-1;i>=0;i--){
                    //we can either buy or not buy
                    dp[i][1] = max(-prices[i] + dp[i+1][0],0 + dp[i+1][1]);
                    //i.e you can sell or you can not sell
                    dp[i][0] = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);                
        }  
        return dp[0][1];
        
        
    }
};