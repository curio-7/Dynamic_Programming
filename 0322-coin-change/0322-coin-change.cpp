class Solution {
public:
    //memo wil not pass
//     int f(vector<int>coins,int amount,int i,vector<vector<int>>&dp){
//         //base case
//         if(i==0){
//             if(amount%coins[i]==0) return amount/coins[i];
//             return 1e9;
//         }
//         //check
//         if(dp[i][amount]!=-1) return dp[i][amount];
//         //explore
//         int notpick = 0 + f(coins,amount,i-1,dp);
//         int pick = INT_MAX;
//         if(coins[i]<=amount) pick = 1 + f(coins,amount-coins[i],i,dp);
        
//         //return 
//         return dp[i][amount] = min(pick,notpick);
//     }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans = f(coins,amount,n-1,dp);
        // return (ans>=1e9)?-1:ans;
        //base case
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t] = 1e9;
        }
        //loop
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int notpick = 0 + dp[i-1][tar];
                int pick = 1e9;
                if(coins[i]<=tar) pick = 1 + dp[i][tar-coins[i]];
                
                dp[i][tar] = min(pick,notpick);
            }
        }
        int ans = dp[n-1][amount];
        return (ans>=1e9)?-1:ans;
    }
};