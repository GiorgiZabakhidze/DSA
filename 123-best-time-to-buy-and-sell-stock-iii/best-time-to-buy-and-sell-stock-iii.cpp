class Solution {
private:    
    int find(vector<int>& prices, int idx, bool buying, int c, vector<vector<vector<int>>>& memo) {
        if(idx >= prices.size() || c < 0)
            return 0;
        if(memo[idx][buying][c] != -1)
            return memo[idx][buying][c];

        if(buying) {
            return memo[idx][buying][c] = max(-prices[idx] + find(prices, idx + 1, !buying, c, memo),
                                                find(prices, idx + 1, buying, c, memo));
        }else {
            return memo[idx][buying][c] = max(prices[idx] + find(prices, idx + 1, !buying, c - 1, memo), 
                                            find(prices, idx + 1, buying, c, memo));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (2, vector<int> (2, -1)));

        return find(prices, 0, true, 1, memo);
    }
};