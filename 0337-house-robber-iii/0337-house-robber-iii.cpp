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
    
    
    pair<int,int> rec(TreeNode *root){
        
         
        pair<int,int>p;
        
        if(!root)return p;
        
        pair<int,int> left=rec(root->left);
        pair<int,int> right=rec(root->right);
       
        p.first=root->val+left.second+right.second;
        p.second=max(left.first,left.second)+max(right.first,right.second);
        
        return p;
    }
    int rob(TreeNode* root) {
        pair<int,int> p = rec(root);
        return max(p.first,p.second);
    }
};