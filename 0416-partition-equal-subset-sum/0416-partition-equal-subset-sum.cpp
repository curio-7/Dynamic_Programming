class Solution {
public:
    bool f(vector<int>arr, int k){
        int n = arr.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(arr[0]<=k) dp[0][arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int j = 1;j<=k;j++){
                bool pick = false;
                if(arr[i]<=j) pick = dp[i-1][j-arr[i]];
                bool notpick = dp[i-1][j];
                dp[i][j] = pick or notpick;
            }
        }
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        if(nums.size()==1) return false;
        if(nums.size()==2 && nums[0]!=nums[1]){
            return false;
        }
        return f(nums,sum/2);
    }
};