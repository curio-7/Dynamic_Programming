class Solution {
public:
    bool f(int i,int j,int k,string&s1,string&s2,string&s3,vector<vector<vector<int>>>&dp){
        //base case
        if(k<0){
            if(i<0 && j<0)return 1;
            else return 0;
        }
        //check
        if(i>=0 && j>=0 && dp[i][j][k]!=-1)return dp[i][j][k];
        //explore
        if(i>=0 && s3[k] == s1[i] && j>=0 && s3[k] == s2[j]){
            bool eitheri = f(i-1,j,k-1,s1,s2,s3,dp);
            bool eitherj = f(i,j-1,k-1,s1,s2,s3,dp);
            return dp[i][j][k] = eitheri or eitherj;
        }
        else if(i>=0 && s3[k] == s1[i]){
            return  f(i-1,j,k-1,s1,s2,s3,dp);
        }
        else if(j>=0 && s3[k] == s2[j]){
            return  f(i,j-1,k-1,s1,s2,s3,dp);
        }
        else return false;
    }
    //since k will be always same as i+j = k so we can furthur optimize it in 2d dp
    bool f2(int i,int j,int k,string&s1,string&s2,string&s3,vector<vector<int>>&dp){
        //base case
        if(k<0){
            if(i<0 && j<0)return 1;
            else return 0;
        }
        //check
        if(i>=0 && j>=0 && dp[i][j]!=-1)return dp[i][j];
        //explore
        if(i>=0 && s3[k] == s1[i] && j>=0 && s3[k] == s2[j]){
            bool eitheri = f2(i-1,j,k-1,s1,s2,s3,dp);
            bool eitherj = f2(i,j-1,k-1,s1,s2,s3,dp);
            return dp[i][j] = eitheri or eitherj;
        }
        else if(i>=0 && s3[k] == s1[i]){
            return  f2(i-1,j,k-1,s1,s2,s3,dp);
        }
        else if(j>=0 && s3[k] == s2[j]){
            return  f2(i,j-1,k-1,s1,s2,s3,dp);
        }
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int p = s3.length();
        if(n+m!=p)return false;
        // vector<vector<vector<int>>>dp1(n+1,vector<vector<int>>(m+1,vector<int>(p+1,-1)));
        // return f(n-1,m-1,p-1,s1,s2,s3,dp1);
        vector<vector<int>>dp2(n+1,vector<int>(m+1,-1));
        return f2(n-1,m-1,p-1,s1,s2,s3,dp2);
    }
};