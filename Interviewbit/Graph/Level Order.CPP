// Problem Link - https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	vector<vector<int>> ans;
	while (!q.empty()) {
		int sz = q.size();
		vector<int> now;
		while (sz--) {
			TreeNode *curr = q.front();
			q.pop();
			now.push_back(curr->val);
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		ans.push_back(now);
	}
	return ans;
}
