class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minLeft = INT_MAX, ans = -1;
        for(auto &it : nums) {
            ans = max(ans, it - minLeft);
            minLeft = min(minLeft, it);
        }
        return ans > 0 ? ans : -1;
    }
};