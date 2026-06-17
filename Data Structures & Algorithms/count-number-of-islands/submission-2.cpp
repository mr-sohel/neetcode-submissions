class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!vis[i][j] and grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};