class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
        int m=grid.size();
        int n=grid[0].size();
        while(k--){
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(i==m-1&&j==n-1)ans[0][0]=grid[i][j];
                    else if(j==n-1){
                        ans[i+1][0]=grid[i][j];
                    }else{
                        ans[i][j+1]=grid[i][j];
                    }

                }
            }
            grid=ans;
        }
        return grid;
    }
};