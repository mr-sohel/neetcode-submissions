public class Solution {
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    void dfs(int r, int c, char[][] grid, int n, int m) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(r + dx[i], c + dy[i], grid, n, m);
        }
    }
    public int NumIslands(char[][] grid) {
        if (grid.Length == 0) return 0;
        int n = grid.Length;
        int m = grid[0].Length;
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
}