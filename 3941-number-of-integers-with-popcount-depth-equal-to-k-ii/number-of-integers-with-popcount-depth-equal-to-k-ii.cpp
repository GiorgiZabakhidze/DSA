class Solution {
public:
class Sgtree{
    public:
    vector<int> segTree;
    Sgtree(int n)
    {
        segTree.resize(4 * n , 0);
    }
    void update(int ind , int i , int l , int r , int val){
        if(l == r){
            segTree[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(ind <= mid)update(ind , 2*i+1 , l , mid , val);
        else update(ind , 2*i+2 , mid+1 , r , val);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int start , int end , int i , int l , int r){
        if(start > r || end < l)return 0;
        else if(start <= l && end >= r)return segTree[i];
        int mid = (l+r)/2;
        return query(start , end , 2*i+1 , l , mid) + query(start , end , 2*i+2 , mid+1 , r);
    }
};
    int depth[64];
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        depth[0] = -1;
        depth[1] = 0;
        depth[2] = 1;
        depth[3] = 2;
        vector<Sgtree> seg(6, Sgtree(n));
        for(int i = 4 ; i < 64 ; i++)
        {
            depth[i] = 1 + depth[__builtin_popcount(i)];
        }
        vector<int> count(n);
        for(int ind = 0 ; ind < n ; ind++)
        {
            int cnt = 0 ;
            long long i = nums[ind];
            if(i < 64)
            {
                cnt = depth[i];
            }
            else
            {
                cnt = depth[__builtin_popcountll(i)] + 1;
            }
            count[ind] = cnt;
            if(cnt < 6)
            {
                seg[cnt].update(ind , 0 , 0 , n - 1 , 1);
                for(int j = 0 ; j < 6 ; j++)
                {
                    if(j != cnt)seg[j].update(ind , 0 , 0 , n - 1 , 0);
                }
            }
        }
        vector<int> ans;
        for(auto &i : queries)
        {
            if(i[0] == 2)
            {
                int cnt;
                if(i[2] < 64)
                {
                    cnt = depth[i[2]];
                }
                else
                {
                    cnt = depth[__builtin_popcountll(i[2])] + 1;
                }
                if(count[i[1]] < 6)seg[count[i[1]]].update(i[1] , 0 , 0 , n - 1 , 0);
                if(cnt < 6)seg[cnt].update(i[1] , 0 , 0 , n - 1 , 1);
                count[i[1]] = cnt;
            }
            else
            {
                ans.push_back(seg[i[3]].query(i[1] , i[2] , 0 , 0 , n - 1));
            }
        }
        return ans;
    }
};