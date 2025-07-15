class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        return helper(nums, 1, 1, 0, n, target);
    }
private:
    bool helper(vector<int>& nums, long long first, long long second, int idx, int &n, long long &target) {
        if(first > target || second > target)
            return false;
        if(idx == n) 
            return first == target && second == target;

        if(helper(nums, first * nums[idx], second, idx + 1, n, target))
            return true;
        if(helper(nums, first, second * nums[idx], idx + 1, n, target))
            return true;
        return false;
    }
};