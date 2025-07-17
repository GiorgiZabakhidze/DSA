class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int i = 0, j = 0;
        int n = classroom.size(), m = classroom[0].size();
        int litterCount = 0;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < m; ++c) {
                if(classroom[r][c] == 'L') {
                    classroom[r][c] = '0' + litterCount;
                    ++litterCount;
                }else if(classroom[r][c] == 'S') {
                    i = r;
                    j = c;
                }
            }
        }
        if(litterCount == 0)
            return 0;
        int bitMax = (1 << litterCount) - 1;
        int maxEnergy[20][20][1024];
        memset(maxEnergy, -1, sizeof(maxEnergy));
        
        int DIR[5] = {0, 1, 0, -1, 0};
        queue<tuple<int, int, int, int>> q;
        q.push({i, j, energy, 0});
        maxEnergy[i][j][0] = energy;
        int ans = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                auto [r, c, e, currMask] = q.front();
                q.pop();

                if(currMask == bitMax)
                    return ans;
                
                if(e == 0)
                    continue;
                
                for(int k = 0; k < 4; ++k) {
                    int ni = r + DIR[k];
                    int nj = c + DIR[k + 1];

                    if(ni < 0 || ni >= n || nj < 0 || nj >= m || classroom[ni][nj] == 'X')
                        continue;
                    
                    int ne = e - 1;
                    int nextMask = currMask;
                    if(classroom[ni][nj] == 'R')
                        ne = energy;
                    else if(classroom[ni][nj] <= '9' && classroom[ni][nj] >= '0')
                        nextMask |= (1 << (classroom[ni][nj] - '0'));
                    
                    if(maxEnergy[ni][nj][nextMask] < ne) {
                        maxEnergy[ni][nj][nextMask] = ne;
                        q.push({ni, nj, ne, nextMask});
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};