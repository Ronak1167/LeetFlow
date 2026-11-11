class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost=0;
        int need=min(need1,need2);
        cost+=(long long)need*min(costBoth,cost1+cost2);
        need1-=need;
        need2-=need;
        cost+=(long long)need1*min(cost1,costBoth);
        cost+=(long long)need2*min(cost2,costBoth);
        return cost;
    }
};