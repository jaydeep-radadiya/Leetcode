class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                profit = max(profit,prices[j]-prices[i]);
            }
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int mxpro = 0;
        
        for(int i=0;i<prices.size();i++){
            minprice = min(minprice,prices[i]);
            mxpro = max(mxpro,prices[i]-minprice);
        }
        return mxpro;
    }
};