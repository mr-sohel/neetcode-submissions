class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = (grid).size();
        int m = (grid[0]).size();
        
        int qr[105];
        int qc[105];
        int head = 0;
        int tail = 0;

        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    qr[tail] = i;
                    qc[tail] = j;
                    tail++;
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int minutes = -1;

        while(head < tail) {
            int current_level_size = tail - head;
            minutes++;

            while(current_level_size--) {
                int r = qr[head];
                int c = qc[head];
                head++;

                for(int i = 0; i < 4; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        qr[tail] = nr;
                        qc[tail] = nc;
                        tail++;
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};