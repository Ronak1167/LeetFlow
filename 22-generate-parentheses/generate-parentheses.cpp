class Solution {
public:
    vector<string>ans;
    void solve(int n,string x,int o,int c){
        if(x.length()==2*n){
            ans.push_back(x);
            return;
        }
        if(o<n)solve(n,x+'(',o+1,c);
        if(c<o)solve(n,x+')',o,c+1);
    }
    vector<string> generateParenthesis(int n) {
        solve(n,"",0,0);
        return ans;
    }
};