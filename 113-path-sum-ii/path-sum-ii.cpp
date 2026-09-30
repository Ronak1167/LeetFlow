/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using node=TreeNode;
    vector<vector<int>>ans;
    void solve(node* root,int t,vector<int>a){
        if(root==nullptr)return;
        t-=root->val;
        a.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            if(t==0){
                ans.push_back(a);
            }
            return;
        }
        solve(root->right,t,a);
        solve(root->left,t,a);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
        solve(root,targetSum,a);
        return ans;
    }
};