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
 using node=TreeNode;
class Solution {
public:
    int height(node* root){
        if(root==nullptr)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int l=height(root->left);
        int r=height(root->right);
        return abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};