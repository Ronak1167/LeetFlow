class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int c=0;
        int mx=-1;
        for(auto x:intervals){
            if(x[1]>mx){
                c++;
                mx=x[1];
            }
        }
        return c;
    }
};