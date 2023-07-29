class Solution {
public:
    static bool cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    bool check(string&a ,string&b){
        if(a.length()!=b.length()+1) return false;
        int i=0;int j=0;
        while(i<a.length()){
            if(j<b.length() && a[i]==b[j]){
                i++;j++;
            }
            else{
                i++;
            }
        }
        if(i==a.length() && j==b.length())return true;
        return false;
    }
    int f(vector<string>& words,int i,int prev,vector<vector<int>>&dp){
        //base case
        if(i>=words.size())return 0;
        //check
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        //pick , notpick
        int notpick =0 + f(words,i+1,prev,dp);
        int pick = 0;
        if(prev==-1 || check(words[i],words[prev])){
            pick = 1 + f(words,i+1,i,dp);
        }
        //return
        return dp[i][prev+1] = max(pick,notpick);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(words,0,-1,dp);
    }
};