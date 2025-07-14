class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == key) {
                nums[i] = -1;
                ans.push_back(i);
                int j = i + 1;
                for(; j - i <= k && j < nums.size(); ++j) {
                    if(nums[j] == key) {
                        break;
                    }else {
                        nums[j] = -2;
                        ans.push_back(j);
                    }
                }
                i = j - 1;
            }
        }
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(nums[i] == -1) {
                int j = i - 1;
                for(; i - j <= k && j >= 0; --j) {
                    if(nums[j] == -1) {
                        break;
                    }else if(nums[j] > 0) {
                        nums[j] = -2;
                        ans.push_back(j);
                    }
                }
                i = j + 1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};