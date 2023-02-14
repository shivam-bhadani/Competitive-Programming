// Problem Link - https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &arr) {
	int n = arr.size();
	vector<int> nsl(n);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (st.empty()) nsl[i] = -1;
		else if (st.top() < arr[i]) nsl[i] = st.top();
		else {
			while (!st.empty() && st.top() >= arr[i]) st.pop();
			if (st.empty()) nsl[i] = -1;
			else nsl[i] = st.top();
		}
		st.push(arr[i]);
	}
	return nsl;
}
