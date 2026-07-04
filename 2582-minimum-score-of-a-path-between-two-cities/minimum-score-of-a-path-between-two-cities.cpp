class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> vis;
    int ans = INT_MAX;

    void dfs(int node) {
        vis[node] = 1;

        for (auto [next, wt] : graph[node]) {
            ans = min(ans, wt);

            if (!vis[next])
                dfs(next);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        graph.resize(n + 1);
        vis.assign(n + 1, 0);

        for (auto &e : roads) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        dfs(1);

        return ans;
    }
};