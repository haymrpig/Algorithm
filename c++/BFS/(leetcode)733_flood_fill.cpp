class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> q;
        int dx[4]={1,-1,0,0} ,dy[4]={0,0,1,-1};
        
        int h = image.size();
        int w = image[0].size();
        vector<vector<int>> visited(h, vector<int> (w,0));
        int ori_color = image[sr][sc];
        
        q.push({sr, sc});
        visited[sr][sc]=1;
        image[sr][sc]= newColor;
        
        while(!q.empty()){
            int px = q.front().first;
            int py = q.front().second;
            image[px][py]=newColor;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = px + dx[i];
                int ny = py + dy[i];
                if(nx<0 || nx>=h || ny<0 || ny>=w || image[nx][ny]!=ori_color || visited[nx][ny]==1) continue;
                q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
        return image;
    }
};