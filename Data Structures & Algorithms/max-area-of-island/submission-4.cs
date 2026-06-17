public class Solution {
    public int n, m;

    public int bfs(int r, int c, int[][] grid, bool[][] vis) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        var q = new Queue<(int, int)>();
        q.Enqueue((r, c));
        vis[r][c] = true;
        int area = 1; 

        while (q.Count > 0) {
            var (cr, cc) = q.Dequeue();
            for(int i = 0; i < 4; i++) {
                int nr = cr + dx[i];
                int nc = cc + dy[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = true;
                    q.Enqueue((nr,nc));
                    area++;
                }
            }
        }
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
                    int area = bfs(i, j, grid, vis);
                    ans = Math.Max(ans, area);
                }
            }
        }
        return ans;
    }
}