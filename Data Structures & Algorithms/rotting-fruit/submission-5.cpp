class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        while(!q.empty()) {
            auto [r,c,cnt] = q.front();
            ans = cnt;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc, cnt + 1});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0;j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
