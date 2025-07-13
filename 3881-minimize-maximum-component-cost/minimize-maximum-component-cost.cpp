class DSU {
    vector<int> parent;
    int cmp;
public: 
    DSU(vector<vector<int>>& edges, int n, int limit) {
        for(int i = 0; i < n; ++i)
            parent.push_back(i);
        cmp = n;
        for(auto &it : edges) {
            if(it[2] > limit) break;
            unionDSU(it[0], it[1]);
        }
    }

    int find(int node) {
        if(parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unionDSU(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if(ra != rb) {
            parent[min(ra, rb)] = max(ra, rb);
            --cmp;
        }
    }

    int getComponentCount() {
        return cmp;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(edges.empty())
            return 0;
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int l = 0, r = edges.back()[2];
        while(l <= r) {
            int mid = (l + r) >> 1;

            if(getComponentCount(edges, n, mid) > k) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return l;
    }
private:
    int getComponentCount(vector<vector<int>>& edges, int n, int mid) {
        DSU d(edges, n, mid);
        // cout << d.getComponentCount() << " " << mid << "\n";
        return d.getComponentCount();
    }
};