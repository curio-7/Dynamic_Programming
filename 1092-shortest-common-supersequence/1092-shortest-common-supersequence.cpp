class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        //lcs
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base case
        for(int i=0;i<=n;i++)dp[i][0] = 0;
        for(int j=0;j<=m;j++)dp[0][j] = 0;
        //loop
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        //this code is similar to how to print lcs
        string ans="";
        int i=n;int j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                //if character matches then add that chr and go to diagonal
                ans += str1[i-1];
                i--;j--;
            }
            //if chr not matches
            else{
                //go to that dir which has max value (up and left)
                int up = dp[i][j-1]; //part of str2
                int left = dp[i-1][j]; //part of str1
                if(up>left){
                    ans += str2[j-1];
                    j--;
                }else{
                    ans += str1[i-1];
                    i--;
                }
            }
        }
        //edge case : if one of the string ends
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};