class Solution {
public:
    //memo
    int f(int i,int j1,int j2,int n,int c,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        //bound
        if(j1<0 || j1>=c || j2<0 || j2>=c){
            return -1e9;
        }
        //base case
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        //explore
        int maxi = -1e9;
        //for robot1
        for(int r1 = -1;r1 <= 1;r1++){
            //for robot2
            for(int r2 = -1;r2<=1;r2++){
                int val = 0;
                if(j1 == j2){
                    val = grid[i][j1] + f(i+1,j1+r1,j2+r2,n,c,grid,dp);
                }else{
                    val = grid[i][j1] + grid[i][j2] + f(i+1,j1+r1,j2+r2,n,c,grid,dp);
                }
                maxi = max(maxi,val);
            }
            
        }
        
        //return req
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //3d
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,n,m,grid,dp);
        //tabulation
        //base case
//         for(int j1 = 0;j1<=m-1;j1++){
//             for(int j2 = 0;j2<=m-1;j2++){
//                 if(j1==j2){
//                     dp[n-1][j1][j2] = grid[n-1][j1];
//                 }else{
//                     dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//                 }
//             }
//         }
//         //iteration
//         for(int i=n-2;i>=0;i--){
//             for(int j1 = 0;j1<m;j1++){
//                 for(int j2 = 0;j2<m;j2++){
//                         int maxi = -1e8;
//                         for(int al =-1;al<=1;al++){
//                             for(int b = -1;b<=1;b++){
//                                 int value = 0;
//                                 //here ew also have to check for boundary conditions
//                                 if(j1==j2){
//                                    value = grid[i][j1];
//                                 }else{
//                                     value = grid[i][j1] + grid[i][j2];
//                                 }
//                                 if(j1+al>=0 || j1+al<m ||j2+b>=0 || j2+b<m){
//                                     value+=dp[i][j1+al][j2+b];
//                                 }
//                                 else{
//                                     value+=-1e8;
//                                 }
//                                 maxi = max(maxi,value);
//                             }
//                         }
//                     dp[i][j1][j2] = maxi;
//                 }
//             }
//         }
        
//         return dp[0][0][m-1];
        //staring row,robot1,robot2;
    }
};