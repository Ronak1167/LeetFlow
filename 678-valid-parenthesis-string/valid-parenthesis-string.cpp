class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string s,int i,int o){
        if(o<0)return false;
        if(i==s.size())return o==0;
        if(dp[i][o]!=-1)return dp[i][o];
        if(s[i]=='(')return solve(s,i+1,o+1);
        if(s[i]==')')return solve(s,i+1,o-1);
        bool ok=false;
        if(s[i]=='*'){
            ok=solve(s,i+1,o);
            bool open=solve(s,i+1,o+1);
            bool close=solve(s,i+1,o-1);
            ok=ok||open||close;
        }
        return dp[i][o]=ok;
    }
    bool checkValidString(string s) {
        int n=s.length();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(s,0,0);
    }
};