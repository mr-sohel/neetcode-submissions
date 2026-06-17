class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;

        int fresh = 0;

        // Initialize
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.emplace(i, j);
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int minutes = -1;

        while(!q.empty()) {
            int sz = q.size();
            minutes++;

            while(sz--) {
                auto [r, c] = q.front(); q.pop();

                for(int i = 0; i < 4; i++) {   // ✅ FIXED
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.emplace(nr, nc);
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};