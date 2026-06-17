class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& grid, int n, int m) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        for (int i = 0; i < 4; i++) {
            dfs(r + dx[i], c + dy[i], grid, n, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
};