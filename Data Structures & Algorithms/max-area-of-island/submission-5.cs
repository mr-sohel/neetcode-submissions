public class Solution {
    public int MaxAreaOfIsland(int[][] grid) 
    {
        int n = grid.Length, m = grid[0].Length;
        int maxArea = 0;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            int[] row = grid[i]; // cache row
            for (int j = 0; j < m; j++)
            {
                if (row[j] != 1) continue;

                int area = 0;
                Stack<int> stack = new Stack<int>();
                stack.Push(i * m + j);
                row[j] = -1; // mark visited

                while (stack.Count > 0)
                {
                    int val = stack.Pop();
                    int r = val / m;
                    int c = val % m;
                    area++;

                    for (int k = 0; k < 4; k++)
                    {
                        int nr = r + dx[k];
                        int nc = c + dy[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                        {
                            stack.Push(nr * m + nc);
                            grid[nr][nc] = -1; // mark visited
                        }
                    }
                }

                maxArea = Math.Max(maxArea, area);
            }
        }

        return maxArea;
    }
}