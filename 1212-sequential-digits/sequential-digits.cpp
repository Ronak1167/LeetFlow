class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int len=2;len<10;len++){
            for(int i=0;i<=s.length()-len;i++){
                int x=stoi(s.substr(i,len));
                if(x>=low&&x<=high)ans.push_back(x);
            }
        }
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};