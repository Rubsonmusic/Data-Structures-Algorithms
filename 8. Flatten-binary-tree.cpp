// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;

        flatten(root->right);
        flatten(root->left);

        if(root->left==NULL) return;
        TreeNode* l = root->left;
        
        if(root->right !=NULL){
            while (l->right!=NULL){
                l = l->right;
            }
            l->right = root->right;
        }
        root->right = root->left;
        root->left = NULL;
    }
};
