//Stock Buy and Sell - Max one Transaction Allowed
//given array of prices of various days
//maximise profit, 1 buy + 1 sell, buy before sell
//approach:
//selling on ith day, buy on min price from 1st to (i-1)th day

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit=0;
        int n= prices.size();
        for (int i=1;i<n;i++){
            int cost= prices[i]-mini;
            maxProfit= max(maxProfit, cost);
            mini= min(mini, prices[i]);
    }
    return maxProfit; 
    }
};