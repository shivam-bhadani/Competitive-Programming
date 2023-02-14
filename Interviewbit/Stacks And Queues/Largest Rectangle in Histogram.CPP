// Problem Link - https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

void nextSmallerRight(vector<int>& arr, vector<int>& nsr) {
	int n = arr.size();
	stack<pair<int, int>> st;
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) nsr[i] = n;
		else if (st.top().first < arr[i]) nsr[i] = st.top().second;
		else {
			while (!st.empty() && st.top().first >= arr[i]) st.pop();
			if (st.empty()) nsr[i] = n;
			else nsr[i] = st.top().second;
		}
		st.push({arr[i], i});
	}
}
void nextSmallerLeft(vector<int>& arr, vector<int>& nsl) {
	int n = arr.size();
	stack<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) nsl[i] = -1;
		else if (st.top().first < arr[i]) nsl[i] = st.top().second;
		else {
			while (!st.empty() && st.top().first >= arr[i]) st.pop();
			if (st.empty()) nsl[i] = -1;
			else nsl[i] = st.top().second;
		}
		st.push({arr[i], i});
	}
}

int Solution::largestRectangleArea(vector<int> &heights) {
	int n = heights.size();
	vector<int> nsr(n), nsl(n);
	nextSmallerRight(heights, nsr);
	nextSmallerLeft(heights, nsl);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, (nsr[i] - nsl[i] - 1) * heights[i]);
	}
	return ans;
}
