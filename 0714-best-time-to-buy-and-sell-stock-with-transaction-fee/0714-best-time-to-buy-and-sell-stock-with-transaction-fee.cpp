class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index = n-1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    int choose = -prices[index] + next[0];
                    int skip = 0 + next[1];

                    profit = max(choose, skip);
                }
                else{
                    int choose = (prices[index] - fee) + next[1];
                    int skip = 0 + next[0];

                    profit = max(choose, skip);
                }

                curr[buy] = profit;

            }

            next = curr;
        }

        return curr[1];
    }
};