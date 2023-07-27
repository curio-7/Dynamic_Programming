class Solution {
public:
    int mod = (int)1e9+7;
    int memo(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
        //base case
        if(j==0) return 1;
        if(i==0) return 0; 
        //check
        if(dp[i][j]!=-1)  return dp[i][j];  
        //explore &  return
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]= memo(i-1,j-1,s1,s2,dp)+memo(i-1,j,s1,s2,dp);
        }
        else return dp[i][j] = memo(i-1,j,s1,s2,dp);
        
    }
    int tab(string& s,string& t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m+1;i++){
            dp[0][i]=0;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){

                if(s[i-1]==t[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return memo(n,m,s,t,dp);
       // return tab(s,t);
    }
};