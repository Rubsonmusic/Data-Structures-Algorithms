/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/delete-nodes-and-return-forest/
// Depth first traversal O(n) space and O(n) time
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)
            return vector<TreeNode*>();
        
        unordered_set<int> delete_it(to_delete.begin(), to_delete.end());

        vector<TreeNode*> ret;

        queue<TreeNode*> q;
        queue<bool> parent_deleted;
        
        q.push(root);
        parent_deleted.push(true);
        
        while(!q.empty()){
            
            auto curr = q.front();
            bool delete_current = false;
            bool parent_dead = parent_deleted.front();
            q.pop(); parent_deleted.pop();

            if(delete_it.count(curr->val)){delete_current=true;}
            
            if(curr->left){
                q.push(curr->left);
                parent_deleted.push(delete_current);
                if(delete_it.count(curr->left->val))
                    curr->left = NULL;
            }
            if(curr->right){
                q.push(curr->right);
                parent_deleted.push(delete_current);
                if(delete_it.count(curr->right->val))
                    curr->right = NULL;
            }
            
            if(!delete_current and parent_dead){
                ret.push_back(curr);
            }
        }
        return ret;
    }
};
