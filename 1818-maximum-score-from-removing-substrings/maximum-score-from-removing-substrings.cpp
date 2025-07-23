class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(y > x) {
            reverse(s.begin(), s.end());
            //swap
            x ^= y;
            y ^= x;
            x ^= y;
        }
        // now the problem greedily becomes searching for "ab" in 0->n-1 order
        // we know that cost of "ab" >= "ba" due to above operations
        cout << x << " " << y;
        string t;
        int ans = 0;
        for(auto &it : s) {
            if(it == 'b' && !t.empty() && t.back() == 'a') {
                t.pop_back();
                ans += x;
            }else {
                t += it;
            }
        }
        string k = "";
        for(auto &it : t) {
            if(it == 'a' && !k.empty() && k.back() == 'b') {
                k.pop_back();
                ans += y;
            }else {
                k += it;
            }
        }
        return ans;
    }
};