public class Solution {
    public int n, m;

    public int dfs(int r, int c, int[][] grid, bool[][] vis) {
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || grid[r][c] == 0) {
            return 0;
        }

        vis[r][c] = true;

        int area = 1;

        area += dfs(r, c + 1, grid, vis);
        area += dfs(r, c - 1, grid, vis);
        area += dfs(r + 1, c, grid, vis);
        area += dfs(r - 1, c, grid, vis);

        return area;
    }

    public int MaxAreaOfIsland(int[][] grid) {
        n = grid.Length;
        m = grid[0].Length;

        bool[][] vis = new bool[n][];
        for (int i = 0; i < n; i++) {
            vis[i] = new bool[m];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int area = dfs(i, j, grid, vis);
                    ans = Math.Max(ans, area);
                }
            }
        }

        return ans;
    }
}