class Solution {
public:
    //3D DP
    int memo(vector<int>&prices,int n,int i,int buy,int maxT,vector<vector<vector<int>>>&dp){
        //base case
        if(i==n || maxT == 0)return 0;
        //check
        if(dp[i][buy][maxT]!=-1)return dp[i][buy][maxT];
        //explore
        int profit = 0;
        if(buy==1){
            //either u can buy it or u cant
            profit = max(-prices[i]+memo(prices,n,i+1,0,maxT,dp),
                      0 + memo(prices,n,i+1,1,maxT,dp));
        }
        else{
            //either u can sell or u cant
            profit =  max(prices[i] + memo(prices,n,i+1,1,maxT-1,dp),
                      0 + memo(prices,n,i+1,0,maxT,dp));
        }
        return dp[i][buy][maxT] = profit;
    }
    int tab(vector<int>&prices,int n){
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //loops
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int maxT = 1;maxT<=2;maxT++){
                    int profit = 0;
                    if(buy==1){
                        //either u can buy it or u cant
                        profit = max(-prices[i]+dp[i+1][0][maxT],
                                  0 + dp[i+1][1][maxT]);
                    }
                    else{
                        //either u can sell or u cant
                        profit =  max(prices[i] + dp[i+1][1][maxT-1],
                                  0 + dp[i+1][0][maxT]);
                    }
                    dp[i][buy][maxT] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    //2D DP
    //beacuse we can observse that if we have max 2 transactions then so order will be B S B S and for even we can buy (0,2) and for odd we can sell(1,3).
    int memo2(vector<int>&prices,int n,int i,int ts,vector<vector<int>>&dp){
        //base case
        if(i==n || ts == 4)return 0;
        if(dp[i][ts]!=-1)return dp[i][ts];
        //explore
        int profit = 0;
        if(ts%2==0){
            //either u can buy it or u cant
            profit = max(-prices[i]+memo2(prices,n,i+1,ts+1,dp),
                      0 + memo2(prices,n,i+1,ts,dp));
        }
        else{
            //either u can sell or u cant
            profit =  max(prices[i] + memo2(prices,n,i+1,ts+1,dp),
                      0 + memo2(prices,n,i+1,ts,dp));
            
        }
        return dp[i][ts] = profit;
    }
    int tab2(vector<int>&prices,int n){
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        //loops
        for(int i=n-1;i>=0;i--){
            for(int ts = 3;ts>=0;ts--){
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //3d dp
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return memo(prices,n,0,1,2,dp);
        // return tab(prices,n);
        //2d dp
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        // return memo2(prices,n,0,0,dp);
        return tab2(prices,n);
    }
};
//do not do unary operations in recursive calls