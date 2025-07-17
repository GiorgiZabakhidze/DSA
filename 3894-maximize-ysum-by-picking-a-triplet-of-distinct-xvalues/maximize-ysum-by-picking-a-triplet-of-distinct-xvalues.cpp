class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> ump;
        for(int i = 0; i < x.size(); ++i) 
            ump[x[i]] = max(ump[x[i]], y[i]);
        if(ump.size() < 3)
            return -1;
        int first = 0, second = 0, third = 0;
        for(auto &it : ump) {
            int &num = it.second;
            if(num > first) {
                third = second;
                second = first;
                first = num;
            }else if(num > second) {
                third = second;
                second = num;
            }else if(num > third) {
                third = num;
            }
        }
        return first + second + third;
    }
};