class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diffSum = 0;
        for(int i = 0; i < n; ++i) {
            diffSum += (gas[i] -= cost[i]);
        }
        if(diffSum < 0)
            return -1;
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += gas[i];

            if(sum < 0) {
                sum = 0;
                ans = i + 1;
            }
        }
        return ans;
        // 5 8 2 8
        // 6 5 6 6

        // -1 3 -4 2
        // -1 2 -2 0

        // -2 -2 -2 3 3
    }
};