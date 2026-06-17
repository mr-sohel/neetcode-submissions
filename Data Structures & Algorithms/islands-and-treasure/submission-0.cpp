class Solution {
public:
    int n, m; 
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void bfs(int r, int c, vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        q.push({r, c, 0});

        while(!q.empty()) {
            auto [cr, cc, cnt] = q.front();
            cnt++;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = cr + dx[i];
                int nc = cc + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] > 0 and grid[nr][nc] > cnt) {
                    grid[nr][nc] = cnt;
                    q.push({nr, nc, cnt});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    bfs(i, j, grid);
                }
            }
        }
        
    }
};
