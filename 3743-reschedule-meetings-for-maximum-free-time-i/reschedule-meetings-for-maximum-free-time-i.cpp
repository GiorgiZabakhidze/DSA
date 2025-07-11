class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> pSum(n + 1);
        for(int i = 0; i < n; ++i) 
            pSum[i + 1] = pSum[i] + (endTime[i] - startTime[i]);
        
        int ans = 0;
        for(int i = k - 1; i < n; ++i) {
            int leftBound = (i == k - 1 ? 0 : endTime[i - k]);
            int rightBound = (i == n - 1 ? eventTime : startTime[i + 1]);
            ans = max(ans, rightBound - leftBound - pSum[i + 1] + pSum[i - k + 1]);
        }
        return ans;
    }
};