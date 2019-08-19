// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
private:
    unordered_map<int, int> sums;
public:
    int maxLevelSum(TreeNode* root) {

        init_sums(root, 0);
        int ret = 1;
        int currmax = INT_MIN;
        for(auto it = sums.begin(); it != sums.end(); it++){
            if(it->second>currmax || (it->second==currmax && it->first<currmax)){
                ret = it->first + 1;
                currmax = it->second;
            }
        }
        return ret;
    }
    
    void init_sums(TreeNode* root, int depth){
        if (root==NULL) return;

        if(sums.count(depth)==0) sums[depth] = 0;
        sums[depth] += root->val;
        init_sums(root->left, depth+1);
        init_sums(root->right, depth+1);
    }
};
