// Problem Link - https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans = INT_MIN;

int solve(TreeNode *root) {
	if (root == nullptr) return 0;
	int l = solve(root->left);
	int r = solve(root->right);
	int gain = max(l, r);
	ans = max({ans, root->val + max(l, 0) + max(r, 0)});
	if (gain > 0) {
		return root->val + gain;
	}
	else {
		return root->val;
	}
}

int Solution::maxPathSum(TreeNode* A) {
	ans = INT_MIN;
	solve(A);
	return ans;
}
