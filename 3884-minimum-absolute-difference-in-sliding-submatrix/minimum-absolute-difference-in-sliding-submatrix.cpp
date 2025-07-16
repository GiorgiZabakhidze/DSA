class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int> (n - k + 1));
        map<int, int> mp; // numbers in K x K grids
        vector<vector<int>> visited(m, vector<int> (n, false));
        for(int i = 0; i < k - 1; ++i) {
            for(int j = 0; j < k - 1; ++j)  {
                ++mp[grid[i][j]];
                visited[i][j] = true;
            }
        }

        for(int i = 0; i + k <= m; ++i) {
            addNextRow(grid, mp, i + k - 1, 0, k, visited);
            for(int j = 0; j + k <= n; ++j) {
                addNextColumn(grid, mp, i, j + k - 1, k, visited);
                ans[i][j] = getValGrid(mp, visited);
                if(j + k < n)
                    negateLastColumn(grid, mp, i, j, k, visited);
            }
            negateLastRow(grid, mp, i, n - k, k, visited);
            ++i;
            if(i + k <= m) {
                addNextRow(grid, mp, i + k - 1, n - k, k, visited);
                ans[i][n - k] = getValGrid(mp, visited);
                for(int j = n - k - 1; j >= 0; --j) {
                    addNextColumn(grid, mp, i, j, k, visited);;
                    negateLastColumn(grid, mp, i, j + k, k, visited);
                    ans[i][j] = getValGrid(mp, visited);
                }
                negateLastRow(grid, mp, i, 0, k, visited);
            }
        }
        return ans;
        // 99503 -64417
        // -48637 -81877
        // -6967 44464. fails on this case when k = 2
    }
private:
    int getValGrid(map<int, int>& mp, vector<vector<int>>& v) {
        int ans = INT_MAX;
        auto curr = mp.begin(); ++curr;
        auto last = mp.begin();

        for(auto &it : v) {
            for(auto &i : it) {
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
        // cout << "starting print : \n";
        // for(auto &it : mp) {
        //     cout << it.first << " " << it.second << "\n";
        // }
        // cout << "finish Print \n";
        // cout << "new \n";
        while(curr != mp.end()) {
            // cout << last->first << " : " << last->second << "\n";
            ans = min(ans, curr->first - last->first);
            ++curr;
            ++last;
        }
        // cout << "answer : " << ans << "\n";
        return ans == INT_MAX ? 0 : ans;
    }

    void addNextRow(vector<vector<int>>& grid, map<int, int>& mp, int row, int col, int &k, vector<vector<int>>& visited) {
        for(int i = 0; i < k; ++i) {
            if(!visited[row][col + i]) {
                ++mp[grid[row][col + i]];
                visited[row][col + i] = true; // mark as visited
            }
        }
    }
    
    void addNextColumn(vector<vector<int>>& grid, map<int, int>& mp, int row, int col, int &k, vector<vector<int>>& visited) {
        for(int i = 0; i < k; ++i) {
            if(!visited[row + i][col]) {
                ++mp[grid[row + i][col]];
                visited[row + i][col] = true; // mark as visited
            }
        }
    }

    void negateLastRow(vector<vector<int>>& grid, map<int, int>& mp, int row, int col, int &k, vector<vector<int>>& visited) {
        for(int i = 0; i < k; ++i) {
            if(--mp[grid[row][col + i]] <= 0) {
                mp.erase(grid[row][col + i]);
            }
            visited[row][col + i] = false;
        }
    }

    void negateLastColumn(vector<vector<int>>& grid, map<int, int>& mp, int row, int col, int &k, vector<vector<int>>& visited) {
        for(int i = 0; i < k; ++i) {
            if(--mp[grid[row + i][col]] <= 0) {
                mp.erase(grid[row + i][col]);
            }
            visited[row + i][col] = false;
        }
    }
}; 