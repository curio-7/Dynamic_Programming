#define all(v) (v).begin(),(v).end()
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1),hash(n,1);
        int maxi = -1e9;
        int lidx = 0;
        sort(all(nums));
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    //update
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lidx = i;
            }
        }
        vector<int>lis;
        lis.push_back(nums[lidx]);
        while(hash[lidx]!=lidx){
            lidx = hash[lidx];
            lis.push_back(nums[lidx]);
        }
        reverse(all(lis));
        return lis;
    }
};