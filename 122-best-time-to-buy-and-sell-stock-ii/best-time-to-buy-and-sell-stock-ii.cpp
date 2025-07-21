class Solution {
private:
    int find(vector<int>& prices, int idx, bool buying, vector<vector<int>>& memo) {
        if(idx >= prices.size())
            return 0;
        if(memo[idx][buying] != -1)
            return memo[idx][buying];
        
        if(buying) {
            return memo[idx][buying] = max(-prices[idx] + find(prices, idx + 1, !buying, memo), 
                                            find(prices, idx + 1, buying, memo));
        }
        //else
        return memo[idx][buying] = max(prices[idx] + find(prices, idx + 1, !buying, memo), 
                                            find(prices, idx + 1, buying, memo));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2, -1));
        return find(prices, 0, true, memo);
    }
};