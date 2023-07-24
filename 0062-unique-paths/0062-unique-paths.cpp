class Solution {
public:
    //recursive tc= O(2^(n*m))
    //memo tc = O(n*m)
    //tabulation tc = O(N*M)
    
    int f(int m,int n,vector<vector<int>>&dp){
        //base case
        if(m<0 || n<0) return 0;
        if(m == 0 && n == 0)return 1;
        //check
        if(dp[m][n]!=-1)return dp[m][n];
        //explore
        int up = f(m-1,n,dp);
        int left = f(m,n-1,dp);
        
        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)dp[i][j]=1;
        //         else{
        //             int up=0;
        //             int left=0;
        //             if(i>0) up = dp[i-1][j];
        //             if(j>0) left = dp[i][j-1];
        //             dp[i][j] = up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        
    }
};