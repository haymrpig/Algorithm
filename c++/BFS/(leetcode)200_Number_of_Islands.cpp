class Solution {
public:
    int h;
    int w;
    int land_idx = 2;
    void BFS(vector<vector<int>>& grid_int, int i, int j){
        queue<pair<int,int>> q;
        int dx[4]={0, 0, 1, -1}, dy[4]={1, -1, 0,0};
        q.push({i,j});
        while(!q.empty()){
            int px = q.front().first;
            int py = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = px + dx[k];
                int ny = py + dy[k];
                if(nx>=0 && nx<h && ny>=0 && ny<w && grid_int[nx][ny]==1){
                    grid_int[nx][ny]=land_idx;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
        w = grid[0].size();
        vector<vector<int>> grid_int(h, vector<int> (w,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                grid_int[i][j]= grid[i][j]=='0'?0:1; 
            }
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid_int[i][j]==1){
                    BFS(grid_int,i, j);
                    land_idx++;
                }
            }
        }
        return land_idx-2;
    }
};