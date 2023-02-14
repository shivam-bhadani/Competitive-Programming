// Problem Link - https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

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

int largestRectangleArea(vector<int>& heights) {
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

int Solution::maximalRectangle(vector<vector<int> > &matrix) {
	int n = matrix.size(), m = matrix[0].size();
	vector<int> ht(m);
	for (int j = 0; j < m; j++) {
		ht[j] = matrix[0][j];
	}
	int ans = largestRectangleArea(ht);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) ht[j] = 0;
			else ht[j] += matrix[i][j];
		}
		ans = max(ans, largestRectangleArea(ht));
	}
	return ans;
}

