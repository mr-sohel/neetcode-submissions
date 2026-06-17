class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        queue<tuple<int,int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        while(!q.empty()) {
            auto [r,c,cnt] = q.front();
            ans = max(ans,cnt);
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 and nr < n and nc >= 0 and nc < m and !vis[nr][nc] and grid[nr][nc] == 1) {
                    vis[nr][nc] = true;
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
