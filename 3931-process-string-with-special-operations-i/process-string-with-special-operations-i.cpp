class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto it : s) {
            if(it >= 'a' && it <= 'z') 
                ans += it;
            else if(it == '*') {
                if(!ans.empty())
                    ans.pop_back();
            }else if(it == '#')
                ans = ans + ans;
            else if(it == '%')
                reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};