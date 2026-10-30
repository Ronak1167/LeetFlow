class Solution {
public:
    int shortestPath(int n,
                      vector<vector<int>>& edges,
                      string labels,
                      int k) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }
        const long long INF = 4e18;
        vector<vector<long long>> dist(n,vector<long long>(k + 1, INF));
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();
            if (d != dist[u][run]) continue;
            for (auto &[v, w] : g[u]) {
                int nr;
                if (labels[v] == labels[u])
                    nr = run + 1;
                else
                    nr = 1;
                if (nr > k) continue;
                if (dist[v][nr] > d + w) {
                    dist[v][nr] = d + w;
                    pq.push({dist[v][nr], v, nr});
                }
            }
        }
        long long ans = INF;
        for (int run = 1; run <= k; run++) {
            ans = min(ans, dist[n - 1][run]);
        }
        return ans == INF ? -1 : (int)ans;
    }
};