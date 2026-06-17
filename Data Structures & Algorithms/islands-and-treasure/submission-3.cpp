class Solution {
public:
    int n, m; 
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void bfs(int r, int c, vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({r, c});

        while(!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = cr + dx[i];
                int nc = cc + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] > grid[cr][cc] + 1) {
                    grid[nr][nc] = grid[cr][cc] + 1;
                    q.push({nr, nc});
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
