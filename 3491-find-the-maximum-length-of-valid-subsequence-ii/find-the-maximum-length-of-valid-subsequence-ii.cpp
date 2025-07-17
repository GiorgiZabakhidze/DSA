class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 0;
        vector<vector<int>> dp(k, vector<int> (k));
        for(auto &it : nums) {
            it %= k;
            for(int prev = 0; prev < k; ++prev) {
                dp[it][prev] = dp[prev][it] + 1;
                ans = max(ans, dp[it][prev]);
            }
        }
        return ans;
    }
};