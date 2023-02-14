// Problem Link - https://www.interviewbit.com/problems/rain-water-trapped/

vector<int> maxLeft(vector<int> &height) {
	vector<int> ans{height[0]};
	for (int i = 1; i < height.size(); i++) {
		ans.push_back(max(height[i], ans[i - 1]));
	}
	return ans;
}
vector<int> maxRight(vector<int> &height) {
	vector<int> ans(height.size());
	ans[height.size() - 1] = height[height.size() - 1];
	for (int i = height.size() - 2; i >= 0; i--) {
		ans[i] = max(height[i], ans[i + 1]);
	}
	return ans;
}

int Solution::trap(const vector<int> &a) {
	vector<int> height = a;
	vector<int> left = maxLeft(height);
	vector<int> right = maxRight(height);
	int ans = 0;
	for (int i = 0; i < height.size(); i++) {
		ans += min(left[i], right[i]) - height[i];
	}
	return ans;
}
