class Solution {
public:
    int n,m;
    void solve(vector<char>&f,int n){
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            if(f[i]=='*'){
                k=i-1;
            }else if(f[i]=='#'){
                f[i]='.';
                f[k]='#';
                k--;
            }
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        n=box[0].size();
        m=box.size();
        for(auto &x:box){
            solve(x,n);
        }
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=box[m-1-j][i];
            }
        }
        return ans;
    }
};