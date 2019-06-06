// https://leetcode.com/problems/binary-tree-level-order-traversal

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	vector<vector<int>> output = {};
	vector<int>level = {}
	if(root==NULL)
		return output;
		
	TreeNode* current;
	q.push(root);
	TreeNode* lastnode = root;
	while(!q.empty()){
		current = q.pop();
		level.push_back(current->val);
		
		if(current->left)
			q.push(current->left);
		if(current->right)
			q.push(current->right);
		
		if (current==lastnode){
			lastnode = q.back();
			output.push_back(level);
			level.clear();
		}
	}
}

