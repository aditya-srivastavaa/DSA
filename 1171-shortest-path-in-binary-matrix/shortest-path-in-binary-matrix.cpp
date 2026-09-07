class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // 1. If start or end is blocked, impossible
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        if (n == 1) return 1;

        // 2. 8 directions (including diagonals)
        int dRow[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dCol[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        // Queue stores {row, col}
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        // Overwrite grid cell to mark visited and store length
        // Start cell length is 1 (LC rule)
        grid[0][0] = 1; 

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dist = grid[r][c];

            // Reached bottom-right target
            if (r == n - 1 && c == n - 1) return dist;

            for (int i = 0; i < 8; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                // Check bounds and if cell is unvisited path (value is 0)
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = dist + 1; // mark visited with new distance
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};