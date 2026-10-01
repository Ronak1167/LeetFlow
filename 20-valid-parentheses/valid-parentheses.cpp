class Solution {
public:
    bool isValid(string s) {
        stack<char>f;
        for(char c:s){
            if(c=='('||c=='['||c=='{')f.push(c);
            else if(c==')'){
                if(f.empty())return false;
                if(f.top()=='(')f.pop();
                else return false;
            }
            else if(c==']'){
                if(f.empty())return false;
                if(f.top()=='[')f.pop();
                else return false;
            }
            else if(c=='}'){
                if(f.empty())return false;
                if(f.top()=='{')f.pop();
                else return false;
            }
        }
        return f.empty();
    }
};