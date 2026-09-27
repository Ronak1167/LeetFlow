class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>s1;
        string curr="";
        for(auto c:s){
            if(c=='('){
                s1.push(curr);
                curr="";
            }else if(c==')'){
                reverse(curr.begin(),curr.end());
                curr=s1.top()+curr;
                s1.pop();
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};