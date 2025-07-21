class Solution {
private:
    int find(vector<int>& prices, int idx, bool buy, int k, vector<vector<int>>& memo) {
        if(idx >= prices.size() || k == 0) 
            return 0;
        if(memo[idx][buy] != -1)
            return memo[idx][buy];
        
        if(buy) {
            return memo[idx][buy] = max(-prices[idx] + find(prices, idx + 1, !buy, k, memo), 
                                        find(prices, idx + 1, buy, k, memo));
        }else {
            return memo[idx][buy] = max(prices[idx] + find(prices, idx + 1, !buy, k - 1, memo), 
                                        find(prices, idx + 1, buy, k, memo));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2, -1));

        return find(prices, 0, true, 1, memo);
    }
};