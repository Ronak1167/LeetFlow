class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int x=*max_element(nums.begin(),nums.end());
        int y=*min_element(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=y;i<=x;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end())ans.push_back(i);
        }
        return ans;
    }
};