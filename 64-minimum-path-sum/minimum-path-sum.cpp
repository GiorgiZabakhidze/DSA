class Solution {
private:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo, int &n, int &m) {
        if(i >= n || j >= m)
            return INT_MAX;
            
        if(i == n - 1 && j == m - 1)
            return grid[i][j];
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int right = helper(grid, i, j + 1, memo, n, m);
        int down = helper(grid, i + 1, j, memo, n, m);
        // int diagonal = helper(grid, i + 1, j + 1, memo, n, m);

        return memo[i][j] = grid[i][j] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> memo(n, vector<int> (m, -1));
        return helper(grid, 0, 0, memo, n, m);
    }
};