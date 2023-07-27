class Solution {
public:
    int f(int i,int j,string&s,string&t,vector<vector<int>>&dp){
        //base case
        if(i==0)return j;
        if(j==0) return i;
        //check
        if(dp[i][j]!=-1)return dp[i][j];
        //explore
        if(s[i-1] == t[j-1]){
            return 0 + f(i-1,j-1,s,t,dp);
        }else{
            int ins = 1 + f(i,j-1,s,t,dp);
            int del = 1 + f(i-1,j,s,t,dp);
            int rep = 1 + f(i-1,j-1,s,t,dp);
            
            return dp[i][j] = min({ins,del,rep});
        }
        
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(word1 == word2)return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2,dp);
    }
};