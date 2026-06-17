class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>> &vis) {
        vis[r][c] = true;
        for(int i = 0; i < 4; i++) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        n = r;
        m = c;
        int ans = 0;
        vector<vector<bool>> vis(r, vector<bool>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(!vis[i][j] and grid[i][j] == '1') {
                    dfs(i,j, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
