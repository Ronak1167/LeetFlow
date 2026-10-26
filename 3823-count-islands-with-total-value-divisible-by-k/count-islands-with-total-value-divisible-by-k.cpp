class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                queue<pair<int,int>>q;
                long long sum=grid[i][j];
                q.push({i,j});
                grid[i][j]=0;
                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int f=0;f<4;f++){
                        int nx=x+dx[f];
                        int ny=y+dy[f];
                        if(nx<m&&ny<n&&ny>=0&&nx>=0&&grid[nx][ny]!=0){
                            sum+=grid[nx][ny];
                            q.push({nx,ny});
                            grid[nx][ny]=0;
                        }
                    }
                }
                if(sum%k==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};