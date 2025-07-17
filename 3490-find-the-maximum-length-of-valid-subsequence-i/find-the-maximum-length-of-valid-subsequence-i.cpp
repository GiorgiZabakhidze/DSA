class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int odds = nums[0] & 1, alternates = 1, prev = nums[0];
        for(int i = 1; i < n; ++i) {
            odds += nums[i] & 1;

            alternates += (nums[i] & 1) != (prev & 1);
            prev = nums[i];
        }
        return max({odds, n - odds, alternates});
    }
};