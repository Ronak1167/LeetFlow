class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        long long sum=mass;
        int c=0;
        for(int i=0;i<n;i++){
            if(asteroids[i]<=sum){
                sum+=asteroids[i];
                c++;
            }
        }
        if(c==n)return true;
        return false;
    }
};