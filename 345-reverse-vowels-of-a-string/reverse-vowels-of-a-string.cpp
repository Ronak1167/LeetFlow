class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<char,int>>v;
        int i=0;
        for(auto c:s){
            char y=tolower(c);
            if(y=='a'||y=='e'||y=='i'||y=='o'||y=='u')v.push_back({c,i});
            i++;
        }
        int f=0,j=v.size()-1;
        while(f<=j){
            swap(s[v[f].second],s[v[j].second]);
            f++;
            j--;
        }
        return s;
    }
};