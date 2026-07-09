class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size());
        vector<int>graph(n,0);
        int countergroup=0;
        for(int i=0;i+1<nums.size();i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                graph[i]=countergroup;
            }else{
                graph[i]=countergroup;
                countergroup++;
            }
        }
        graph[n-1]=countergroup;
        for(int i=0;i<queries.size();i++){
            if(graph[queries[i][0]]==graph[queries[i][1]]){
                ans[i]=true;
            }else ans[i]=false;
        }
        return ans;

    }
};