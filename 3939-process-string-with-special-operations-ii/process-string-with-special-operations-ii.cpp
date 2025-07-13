class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for(auto it : s) {
            if(islower(it))
                len++;
            else if(it == '*') {
                if(len > 0)
                    --len;
            }else if(it == '#')
                len <<= 1;
        }
        if(k + 1 > len)
            return char('.');
        return getKth(s, k, len);
    }
private:
    char getKth(string &s, long long k, long long len) {
        for(int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if(islower(c)) {
                --len;
                if(k == len)
                    return c;
            }else if(c == '*') {
                if(len > 0)
                    ++len; 
            }else if(c == '#') {
                long long mid = len >> 1;
                if(k >= mid)
                    k -= mid;
                len = mid;
            }else { //  c == '%'
                k = (len - k - 1);
            }
        }
        return char('.');
    }
};