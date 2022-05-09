// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
        
    int maxProfit(vector<int>& prices) {
        
        int buyDate = 0;
        int sellDate = 0;
        int profit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++) {
            if(prices[i]>=prices[i-1]) {
                sellDate++;
            }
            else {
                profit+=prices[sellDate] - prices[buyDate];
                buyDate = i;
                sellDate = i;
            }
        }
        
        profit+= prices[sellDate] - prices[buyDate];
        
        return profit;
    }
};
