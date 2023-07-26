class Solution {
public:
    //memo
    // int f(int i,int j,int n,int m,vector<vector<int>>&triangle,vector<vector<int>>&dp){
    //     //base case
    //     if(i==n-1)return triangle[n-1][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     //explore
    //     int down = triangle[i][j] + f(i+1,j,n,m,triangle,dp);
    //     int dia = triangle[i][j] + f(i+1,j+1,n,m,triangle,dp);
    //     //min
    //     return dp[i][j] = min(down,dia);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(0,0,n,m,triangle,dp);
        //tabulation
        //base case
        // for(int j=0;j<n;j++){
        //     dp[n-1][j] = triangle[n-1][j];
        // }
        // for(int i=n-2;i>=0;--i){
        //     for(int j=i;j>=0;j--){
        //         int d = triangle[i][j] + dp[i+1][j];
        //         int dg = triangle[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(dg,d);
        //     }
        // }
        // return dp[0][0];
        //spcae optimization
        vector<int>last(n,0),curr(n,0);
        for(int j=0;j<n;j++){
            last[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;--i){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j] + last[j];
                int dg = triangle[i][j] + last[j+1];
                curr[j] = min(dg,d);
            }
            last = curr;
        }
        return last[0];
    }
    //in this it is preferrable to start from top 
};