class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> left_sums(n + 1, 0);
        priority_queue<int> pq;
        long long leftSum = 0;
        for(int i = 0; i < 2 * n; ++i) {
            int &it = nums[i];
            pq.push(it);
            leftSum += it;
            if(pq.size() > n) {
                leftSum -= pq.top();
                pq.pop();
            }
            if(pq.size() == n)
                left_sums[i - n + 1] = leftSum;
        }

        priority_queue<int, vector<int>, greater<>> minHeap;
        vector<long long> right_sums(n + 1, 0);
        long long rightSum = 0;
        for(int i = nums.size() - 1; i >= n; --i) {
            int &it = nums[i];
            minHeap.push(it);
            rightSum += it;
            if(minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n)
                right_sums[i - n] = rightSum;
        }
        // for(auto &it : left_sums)
        //     cout << it << " ";
        // cout << "\n";
        // for(auto &it : right_sums)
        //     cout << it << " ";
        // cout << "\n";
        long long ans = LLONG_MAX;
        for(int i = 0; i <= n; ++i) {
            ans = min(ans, left_sums[i] - right_sums[i]);
        }
        return ans;
    }
};