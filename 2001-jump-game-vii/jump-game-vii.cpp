class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (i == 0 || s[i] == '2')
                for (j = max(j, i + minJump); j <= min((int)s.size() - 1, i + maxJump); ++j)
                    if (s[j] == '0')
                        s[j] = '2';
        return s[s.size() - 1] == '2';
    } 
};