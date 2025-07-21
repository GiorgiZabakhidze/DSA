class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(auto &it : s) {
            if(ans.size() >= 2 && it == ans.back() &&  it == ans[ans.size() - 2])
                continue;
            ans += it;
        }
        return ans;
    }
};