class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int maxi = 0;

        queue<pair<pair<int,int>,int>> bfs;
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    bfs.push({{i,j},time});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!bfs.empty()){
            int x = bfs.front().first.first;
            int y = bfs.front().first.second;

            int t = bfs.front().second;

            bfs.pop();

            maxi = max(maxi,t);

            for(int i=0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < m && newy < n && newy >=0 && !vis[newx][newy] && grid[newx][newy] == 1){
                    vis[newx][newy] = 1;
                    grid[newx][newy] = 2;
                    bfs.push({{newx,newy},t+1});
                }
            }

        }

         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return maxi;
    }
};