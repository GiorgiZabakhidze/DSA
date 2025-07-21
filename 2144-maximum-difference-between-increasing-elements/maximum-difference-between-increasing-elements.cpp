class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minLeft = INT_MAX, ans = -1;
        for(auto &it : nums) {
            if(minLeft < it)
                ans = max(ans, it - minLeft);
            minLeft = min(minLeft, it);
        }
        return ans;
    }
};