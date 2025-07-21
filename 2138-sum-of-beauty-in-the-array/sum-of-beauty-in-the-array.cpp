class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> beauty(n, 0);
        int maxLeftSoFar = nums[0];
        for(int i = 1; i < nums.size() - 1; ++i) {
            if(maxLeftSoFar < nums[i]) {
                beauty[i] = -2;
            }else if(nums[i - 1] < nums[i]) {
                beauty[i] = -1;
            }
            maxLeftSoFar = max(maxLeftSoFar, nums[i]);
        }

        int maxRightSoFar = nums.back();
        for(int i = nums.size() - 2; i > 0; --i) {
            if(nums[i] < maxRightSoFar && beauty[i] == -2) {
                beauty[i] = 2;
            }else if(nums[i] < nums[i + 1] && beauty[i] <= -1) {
                beauty[i] = 1;
            }else {
                beauty[i] = 0;
            }
            maxRightSoFar = min(maxRightSoFar, nums[i]);
        }

        int ans = 0;
        for(auto &it : beauty)
            ans += it;
        return ans;
    }
};