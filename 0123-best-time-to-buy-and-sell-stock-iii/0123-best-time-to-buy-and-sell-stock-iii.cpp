class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();

         int maxEle = prices[n-1];

         int buy_sell_max = 0;

         int sell_buy_sell_max = prices[n-1];

         int maxAns = 0;

         int prev_buy_sell = 0;

         for(int i = n-2; i >= 0; i--){
             prev_buy_sell = buy_sell_max;
            buy_sell_max = max(buy_sell_max,maxEle - prices[i]);
            maxEle = max(maxEle,prices[i]);

            // if i buy at this index and want to make 2 transactions

            maxAns = max(maxAns, max(buy_sell_max, sell_buy_sell_max - prices[i]));

            sell_buy_sell_max  = max(sell_buy_sell_max,prices[i] + prev_buy_sell);
         }

         return maxAns;
    }
};

