class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>p;
        vector<int>mx;
        int max1=INT_MIN;
        for(int i=0;i<n;i++){
            max1=max(nums[i],max1);
            mx.push_back(max1);
        }
        for(int i=0;i<n;i++){
            int x=gcd(mx[i],nums[i]);
            p.push_back(x);
        }
        sort(p.begin(),p.end());
        int l=0,r=p.size()-1;
        long long sum=0;
        while(l<r){
            sum+=gcd(p[l],p[r]);
            l++;
            r--;
        }
        return sum;
    }
};