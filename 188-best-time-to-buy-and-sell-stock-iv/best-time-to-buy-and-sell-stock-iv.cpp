class Solution {
private:
    int find(vector<int>& prices, int idx, bool buying, int k, vector<vector<vector<int>>>& memo) {
        if(idx >= prices.size() || k < 0) 
            return 0;
        if(memo[idx][buying][k] != -1)
            return memo[idx][buying][k];
        
        if(buying) {
            return memo[idx][buying][k] = max(-prices[idx] + find(prices, idx + 1, !buying, k, memo),
                                            find(prices, idx + 1, buying, k, memo));
        }else {
            return memo[idx][buying][k] = max(prices[idx] + find(prices, idx + 1, !buying, k - 1, memo), 
                                            find(prices, idx + 1, buying, k, memo));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (2, vector<int> (k, -1)));
        return find(prices, 0, true, k - 1, memo);
    }
};