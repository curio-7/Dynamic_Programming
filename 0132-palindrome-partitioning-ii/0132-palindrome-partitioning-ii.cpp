class Solution {
public:
    bool isPal(string& s,int i,int j){
       
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int f(int i,int n,string s,vector<int>&dp){
        //base case
        if(i==n)return 0;
        //check
        if(dp[i]!=-1)return dp[i];
        //explore
        int mini = INT_MAX;
        for(int idx=i;idx<n;idx++){
            if(isPal(s,i,idx)){
                int cost = 1 + f(idx+1,n,s,dp);
                mini = min(mini,cost);
            }
            
        }
        return dp[i] = mini;
    }
    int tab(string&s,int n){
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int mini = INT_MAX;
            for(int idx=i;idx<n;idx++){
                if(isPal(s,i,idx)){
                    int cost = 1 + dp[idx+1];
                    mini = min(mini,cost);
                }

            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
    int minCut(string s) {
        int n = s.length();
        // vector<int>dp(n+2,-1);
        // return f(0,n,s,dp)-1;
        return tab(s,n);
    }
};