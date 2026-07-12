class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<pair<int,int>> a;

        for(int i = 0; i < arr.size(); i++)
            a.push_back({arr[i], i});

        sort(a.begin(), a.end());

        vector<int> ans(arr.size());

        int rank = 1;
        ans[a[0].second] = rank;

        for(int i = 1; i < a.size(); i++) {
            if(a[i].first != a[i-1].first)
                rank++;

            ans[a[i].second] = rank;
        }

        return ans;
    }
};