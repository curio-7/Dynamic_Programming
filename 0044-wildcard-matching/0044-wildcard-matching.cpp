class Solution {
public:
    bool f(int i,int j, string &s,string &p,vector<vector<int>> &dp)
    {
        
        if(i==0 && j==0) return true;
        if(j==0 && i>0) return false;
        if(i==0 && j>0)
        {
            while(j>0)
            {
                if(p[j-1]=='*') j--;
                else return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        
        if(p[j-1]=='*')
        {
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp) ? 1:0;//treating * as a "" or as a seq of chr, see notes
        }
        return false;
        
    }
    bool tab(string s,string p){
        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
        //return tab(s,p);
    }
};