class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int cnt = 0;
        vector<bool> dp(s.size());
        dp[0] = true;
        for (int i = minJump; i < s.size(); ++i) {
            cnt += dp[i - minJump];
            if (i - maxJump > 0)
                cnt -= dp[i - maxJump - 1];
            dp[i] = s[i] == '0' && cnt;
        }
        return dp.back();
    }  
};