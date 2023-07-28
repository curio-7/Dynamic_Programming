class Solution {
public:
    int memo(vector<vector<int>>&dp,vector<int>&prices,int i,int buy,int n){
        //base case
        if(i==n)return 0;
        //check
        if(dp[i][buy]!=-1)return dp[i][buy];
        //explore
        int profit = 0;
        if(buy){
            //we can either buy or not buy
            profit = max(-prices[i] + memo(dp,prices,i+1,0,n),0 + memo(dp,prices,i+1,1,n));
        }
        if(!buy){
            //i.e you can sell or you can not sell
            profit = max(prices[i] + memo(dp,prices,i+1,1,n), 0 + memo(dp,prices,i+1,0,n));
        }
        return dp[i][buy] = profit;
        
    }
    int tab(vector<int>&prices,int n){
        vector<vector<int>>dp(n+1,vector<int>(2,0));
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
                    profit = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
            
            
        }
        return dp[0][1];
        
    }
    int anotherOne(vector<int>&prices){
        int ans = 0 ;
        for(int i = 1 ; i < prices.size() ; i++){
            ans += max(prices[i] - prices[i-1] , 0);
        }
        return ans ;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return memo(dp,prices,0,1,n);
        // return tab(prices,n);
        return anotherOne(prices);
    }
};