class Solution {
public:
    int f(vector<vector<int>>&dp,vector<vector<int>> &mat, int i, int j, int n) {
        if (j < 0 || j >= n) return 1e8; 
        if (i == 0) return mat[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        //explore
        int ans = 1e9;
        for(int k = 0;k < n ; k++){
            if(k == j)continue;
            else{
               ans = min(ans, f(dp,mat,i - 1, k,n) + mat[i][j]);
            }
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
         int mini = INT_MAX;
         vector<vector<int>>dp(n,vector<int>(n,-1));
        
         for(int i=0;i<n;i++){
             dp[0][i]=grid[0][i];
         }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ans=INT_MAX;
                for(int k=0;k<grid.size();k++){
                    if(j==k) continue;
                    ans=min(ans,grid[i][j]+dp[i-1][k]);
                }
                dp[i][j]=ans;
            }
        }
        for(int i=0;i<n;i++){
            mini = min(mini,dp[n-1][i]);
        }
        
        return mini;
        

    }
};