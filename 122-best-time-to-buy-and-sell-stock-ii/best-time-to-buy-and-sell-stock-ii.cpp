class Solution {
private:
    int find(vector<int>& prices, int idx, bool buying, vector<vector<int>>& memo) {
        if(idx >= prices.size())
            return 0;
        if(memo[idx][buying] != -1)
            return memo[idx][buying];

        int bought = find(prices, idx + 1, !buying, memo);
        int skipped = find(prices, idx + 1, buying, memo);
        
        if(buying) {
            return memo[idx][buying] = max(-prices[idx] + bought, skipped);
        }
        //else
        return memo[idx][buying] = max(prices[idx] + bought, skipped);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2, -1));
        return find(prices, 0, true, memo);
    }
};