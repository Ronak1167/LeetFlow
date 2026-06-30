class Solution {
public:
    int numberOfSubstrings(string s) {
        int total=0;
        vector<int>p(3,-1);
        for(int i=0;i<s.length();i++){
            p[s[i]-'a']=i;
            total+=min({p[0],p[1],p[2]})+1;
        }
        return total;
    }
    
};