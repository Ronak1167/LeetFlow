class Solution {
public:
    int dc[4]={0,0,1,-1};
    int dr[4]={1,-1,0,0};
    int n;
    vector<vector<int>>dist;
    bool check(int val){
        if(dist[0][0]<val)return false;
        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1&&c==n-1)return true;
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=dc[k]+c;
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&!visited[nr][nc]&&dist[nr][nc]>=val){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        dist.assign(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&dist[nr][nc]>dist[r][c]+1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        int low=0;
        int high=0;
        for(auto x:dist){
            for(int y:x)high=max(high,y);
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid)){
                low=mid+1;
                ans=mid;
            }else high=mid-1;
        }
        return ans;
    }
};