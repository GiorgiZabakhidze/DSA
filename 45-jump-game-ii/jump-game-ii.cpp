class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e6);
        dp.back() = 0;
        for(int i = n - 2; i >= 0; --i) {
            for(int j = nums[i]; j >= 1; --j) {
                dp[i] = min(dp[i], dp[min(i + j, n - 1)] + 1);
            }
        }
        return dp[0];
    }
};