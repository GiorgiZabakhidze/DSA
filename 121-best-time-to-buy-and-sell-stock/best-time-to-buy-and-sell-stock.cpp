class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX;
        int ans = 0;
        for(auto &it : prices) {
            ans = max(ans, it - minSoFar);
            minSoFar = min(minSoFar, it);
        }
        return ans;
    }
// private:
//     int dp(vector<int>& prices, )
};