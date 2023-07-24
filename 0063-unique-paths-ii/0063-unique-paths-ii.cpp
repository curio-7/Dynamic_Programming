class Solution {
public:
    int f(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
        //base case
        if(i == 0 && j == 0)return 1;
        if((i<0 || j<0) || (grid[i][j]==1))return 0;
        //check
        if(dp[i][j]!=-1)return dp[i][j];
        //explore
        int left = f(grid,dp,i-1,j);
        int up = f(grid,dp,i,j-1);
        
        return dp[i][j] = up + left;
    }
    int tab(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //base case
        for(int i=0;i<n;i++)
        {   if(grid[i][0]!=1) dp[i][0]=1;
            else break;
        }
        for(int j=0;j<m;j++)
        {   if(grid[0][j]!=1) dp[0][j]=1;
            else break;
        }
        //explore
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(grid[i][j]!=1){
                    int left = dp[i-1][j];
                    int up = dp[i][j-1];

                    dp[i][j] = up + left;
                }
                
            }
        }
        
        return dp[n-1][m-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(grid,dp,m-1,n-1);
        return tab(grid);
    }
};