#define all(v) (v).begin(),(v).end()
class Solution {
public:
    //idea:
    //pick and not pick chalega 
    //pick kroge toa len ko update kr dena and max ko dekhte rhna
    //not pick kroge toa next wale mien chale jana 
    //ham compare kisse karenge
    //ham compare krenge curr idx wale ele ko prev idx wale ele se 
    //if stict inc tabhi len mein lenge wrna noi
    //tc = O(n2)
    //tumhe bas dhyan dena h ki next elem ko kaise compare kroge || ya next ele kaise choose krna h
    int f(vector<int>&nums,int n,int c,int p,vector<vector<int>>&dp){
        //base case
        if(c==n)return 0;
        //check
        if(dp[c][p+1]!=-1) return dp[c][p+1];
        //calls
        //pick
        //when our prev ind is -1 i.e first elem or strictly inc 
        int pick = 0;
        if(p==-1 || nums[c]>nums[p]){
            pick = 1 + f(nums,n,c+1,c,dp);
        }
        int notpick = 0 + f(nums,n,c+1,p,dp);
        //return
        //p+1 ?? => because when p=-1 invalid index so usko 0 se and n-1 ko n se show krenge
        return dp[c][p+1] =  max(pick,notpick);
    }
    int tab(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //usme 0 se n-1 so idhr n-1 se 0
        for(int c=n-1;c>=0;c--){
            for(int p=c-1;p>=-1;p--){
                int pick = 0;
                if(p==-1 || nums[c]>nums[p]){
                    pick = 1 + dp[c+1][c+1];
                }
                int notpick = 0 + dp[c+1][p+1];
                //return
                //p+1 ?? => because when p=-1 invalid index so usko 0 se and n-1 ko n se show krenge
                dp[c][p+1] =  max(pick,notpick);
            }
        }
        return dp[0][0];
    }
    //bs = O(nlogn)
    //not a intuitive sol but noice sol 
    int bs(vector<int>&nums){
        vector<int>ans;
        ans.emplace_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.emplace_back(nums[i]);
            }else{
                //find lb logn just bade ka index find kro and replace maro
                int idx = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx] = nums[i];
            }
        }
        //ans ele will not be in increasing way but size is.
        return ans.size();
    }
    int so(vector<int>&nums){
        int n = nums.size();
        vector<int>next(n+1,0),curr(n+1,0);
        for(int c=n-1;c>=0;c--){
            for(int p=c-1;p>=-1;p--){
                int pick = 0;
                if(p==-1 || nums[c]>nums[p]){
                    pick = 1 + next[c+1];
                }
                int notpick = 0 + next[p+1];
                curr[p+1] =  max(pick,notpick);
            }
            next = curr;
        }
        return curr[0];
        //tc = O(n2) and sc = O(n*2)
        
    }
    int moreso(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i]) dp[i] = max(dp[i],1+dp[prev]);
            }
        }
        return *max_element(all(dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        //  int n = nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));//state change pr focus kro
        // //becasue prev wala ptr -1 se n-1 tak jaiga
        // return f(nums,n,0,-1,dp);
        // return tab(nums);
         // return bs(nums);
        return moreso(nums);
    }
     
};