// Path With Minimum Effort

class Solution {
public:
    
    const int INF = 1000000000;
    vector<vector<pair<int, int>>> adj;
    int dt[5] = {0, 1, 0, -1, 0};
    
    bool isValid(int x, int y, int n, int m) {
        return (x >= 0) && (y >= 0) && (x < n) && (y < m);
    }

    int dijkstra(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> d(m*n, INF);
        

        d[0] = 0;
        set<pair<int, int>> q;
        q.insert({0, 0});
        while (!q.empty()) {
            int effort = q.begin()->first;
            int curr = q.begin()->second;
            int x = curr / m;
            int y = curr % m;
            
            if(x == n - 1 && y == m - 1)
                return effort;
            
            q.erase(q.begin());

            for (int i = 0; i < 4; i++) {
                int x1 = x + dt[i];
                int y1 = y + dt[i + 1];
                
                int in = x1*m + y1;
                

                if (isValid(x1, y1, n, m) && max(abs(grid[x][y] - grid[x1][y1]), d[curr]) < d[in]) {
                    q.erase({d[in], in});
                    d[in] = max(abs(grid[x][y] - grid[x1][y1]), d[curr]);
                    
                    q.insert({d[in], in});
                }
            }
        }
        return 0;
    }
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        return dijkstra(grid);
    }
};