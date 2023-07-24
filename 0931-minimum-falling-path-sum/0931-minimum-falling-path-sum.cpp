class Solution {
public:
    int memo(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        //base case
        if(j<0 || j>m-1)return 1e9;
        if(i == 0) return dp[i][j];
        //check
        if(dp[i][j]!=-1)return dp[i][j];
        //explore
        int l_d = grid[i][j] + memo(i-1,j-1,n,m,grid,dp);
        int up = grid[i][j] + memo(i-1,j,n,m,grid,dp);
        int r_d = grid[i][j] + memo(i-1,j+1,n,m,grid,dp);
        
        return dp[i][j] = min({l_d,up,r_d});
    }
    int tab(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j] = grid[0][j];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;  
                int up=grid[i][j] + dp[i-1][j];
                if(j-1>=0)ld=grid[i][j] + dp[i-1][j-1];
                if(j+1<m)rd=grid[i][j] + dp[i-1][j+1];
                dp[i][j] = min(up,min(ld,rd)); 
            }
        }
        
        int mini=dp[n-1][0];
        
        for(int j=1;j<m;j++)
        {
            
            mini=min(mini,dp[n-1][j]);
            
        }
        return mini;
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         int mini = 1e9;
//         for(int j = 0;j<m;j++){
//             mini = min(mini,memo(n-1,j,n,m,grid,dp));
//         }
        
//         return mini;
        return tab(grid);
        
    }
};