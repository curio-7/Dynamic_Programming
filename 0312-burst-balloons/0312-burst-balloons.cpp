class Solution {
public:
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        //base case
        if(i>j)return 0;
        //chcek
        if(dp[i][j]!=-1)return dp[i][j];
        //explore
        int maxi = -1e9;
        for(int idx=i;idx<=j;idx++){
            int coins = (nums[i-1]*nums[idx]*nums[j+1]) + f(i,idx-1,nums,dp) + f(idx+1,j,nums,dp);
            maxi = max(maxi,coins);
        }
        //return
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(302,vector<int>(302,0));
        //return f(1,n,nums,dp);
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                //base case
                //if(i>j)continue;
                int maxi = INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int coins = (nums[i-1]*nums[idx]*nums[j+1]) + dp[i][idx-1] + dp[idx+1][j];
                    maxi = max(maxi,coins);
                }
                //return
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
        
    }
};