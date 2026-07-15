class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int x=0,y=0;
        for(int i=1;i<=(2*n);i++){
            if(i%2==0)x+=i;
            else y+=i;
        }
        return gcd(x,y);
    }
};