class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        arr[start] = -arr[start];
        while(!q.empty()) {
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0)
                return true;
            
            int ne1 = idx + arr[idx];
            int ne2 = idx - arr[idx];
            if(ne1 >= 0 && arr[ne1] >= 0) {
                arr[ne1] = -arr[ne1];
                q.push(ne1);
            }
            if(ne2 < n && arr[ne2] >= 0) {
                arr[ne2] = -arr[ne2];
                q.push(ne2);
            }
        }
        return false;
    }
};