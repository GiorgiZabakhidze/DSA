class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxPossible = 0;
        for(int i = 0; i < n; ++i) {
            if(i > maxPossible)
                return false;
            maxPossible = max(maxPossible, i + nums[i]);
        }
        return maxPossible >= nums.size() - 1;
    }
};