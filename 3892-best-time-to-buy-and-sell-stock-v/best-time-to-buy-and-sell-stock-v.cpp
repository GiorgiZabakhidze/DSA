class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<vector<vector<long long>>> memo(prices.size(), vector<vector<long long>> (k + 1, vector<long long> (3, -1)));
        return helper(prices, 0, k, 0, memo);
    }
private:
    long long helper(vector<int>& prices, int idx, int k, int decider, vector<vector<vector<long long>>>& memo) {
        if(idx >= prices.size()) {
            if(k >= 0 && decider == 0)
                return 0;
            return INT_MIN;
        }

        if(memo[idx][k][decider] != -1)
            return memo[idx][k][decider];
        
        long long take = INT_MIN;
        if(k > 0) {
            if(decider == 1) {
                take = prices[idx] + helper(prices, idx + 1, k - 1, 0, memo);
            }else if(decider == 2) {
                take = -prices[idx] + helper(prices, idx + 1, k - 1, 0, memo);
            }else {
                take = max(prices[idx] + helper(prices, idx + 1, k, 2, memo), 
                            -prices[idx] + helper(prices, idx + 1, k, 1, memo));
            }
        }
        long long skip = helper(prices, idx + 1, k, decider, memo);

        return memo[idx][k][decider] = max(skip, take);
    }
};