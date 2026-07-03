class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>>graph(n);
        vector<int>indegree(n,0);
        int mx=0;
        for(auto e:edges){
            graph[e[0]].push_back({e[1],e[2]});
            indegree[e[1]]++;
            mx=max(mx,e[2]);
        }
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto x:graph[u]){
                if(--indegree[x.first]==0)q.push(x.first);
            }
        }
        auto check=[&](int limit)->bool{
            vector<long long>dp(n,LLONG_MAX);
            dp[0]=0;
            for(int u:topo){
                if(dp[u]==LLONG_MAX)continue;
                if(!online[u])continue;
                for(auto p:graph[u]){
                    int node=p.first;
                    long long cost=p.second;
                    if(cost<limit||!online[node])continue;
                    long long newcost=dp[u]+cost;
                    if(newcost<dp[node])dp[node]=newcost;
                }
            }
            return dp[n-1]<=k;
        };
        int l=0,h=mx;
        int ans=-1;
        while(l<=h){
            int mid=l+h;
            mid/=2;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else h=mid-1;
        }
        return ans;
    }
};