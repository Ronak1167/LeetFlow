using ll=long long;
class Solution {
public:
    int n,m,dir;
    vector<vector<int>>nums;
    const int mod=1e9+7;
    vector<vector<vector<int>>>dp;
    int solve(int i,int j,int dir){
        if(i==m-1&&j==n-1)return 1;
        if(i>=m||j>=n)return 0;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        if(nums[i][j]==1){
            if(dir==0){
                dp[i][j][dir]=solve(i+1,j,1);
            }else dp[i][j][dir]=solve(i,j+1,0);
        }else{
            dp[i][j][dir]=(solve(i+1,j,1)+solve(i,j+1,0))%mod;
        }
        return dp[i][j][dir];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid[0].size();
        m=grid.size();
        nums=grid;
        dp.assign(m,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,0,0);
    }
};