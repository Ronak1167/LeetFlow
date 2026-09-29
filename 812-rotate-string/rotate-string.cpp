class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()==goal.length()){
            return (s+s).find(goal)!=string::npos;
        }
        return false;
    }
};