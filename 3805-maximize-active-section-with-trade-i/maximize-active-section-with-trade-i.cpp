class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c : s)
            if(c == '1')
                ones++;
        string t = "1" + s + "1";
        int n = t.size();
        int ans = ones;
        int i = 1;
        while(i < n - 1) {
            if(t[i] == '0') {
                int l = 0;
                while(i < n - 1 && t[i] == '0') {
                    l++;
                    i++;
                }
                int j = i;
                int m = 0;
                while(j < n - 1 && t[j] == '1') {
                    m++;
                    j++;
                }
                if(m == 0) continue;
                int k = j;
                int r = 0;
                while(k < n - 1 && t[k] == '0') {
                    r++;
                    k++;
                }
                if(r > 0)
                    ans = max(ans, ones + l + r);

                i = j;
            } else {
                i++;
            }
        }
        return ans;
    }
};