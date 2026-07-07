class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        string y=to_string(n);
        for(int i=0;i<y.length();i++){
            if((y[i]-'0')>0){
                int r=y[i]-'0';
                x=(x*10)+r;
                sum+=r;
            }
        }
        return x*sum;
    }
};