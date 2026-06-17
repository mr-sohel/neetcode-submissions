public class Solution {
    int n, m;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int MaxAreaOfIsland(int[][] grid) {
        n = grid.Length;
        m = grid[0].Length;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.Max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }

    int dfs(int r, int c, int[][] grid) {
        grid[r][c] = 0; // Mark visited immediately
        int area = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // Boundary and island check
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                area += dfs(nr, nc, grid);
            }
        }
        return area;
    }
}