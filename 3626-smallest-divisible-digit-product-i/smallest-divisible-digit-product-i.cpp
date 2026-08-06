class Solution {
public:
    int pro(int x){
        int p=1;
        while(x>0){
            int r=x%10;
            x/=10;
            p*=r;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        int x=n;
        while(pro(x)%t!=0)x++;
        return x;
    }
};