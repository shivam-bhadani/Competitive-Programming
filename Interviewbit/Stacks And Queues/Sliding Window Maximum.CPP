// Problem Link - https://www.interviewbit.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
vector<int> Solution::slidingMaximum(const vector<int> &a, int k) {
	int n = a.size();
	vector<int> ans;
	int i = 0, j = 0;
	list<int> l;
	while (j < n) {
		while (!l.empty() && l.back() < a[j]) l.pop_back();
		l.push_back(a[j]);
		if (j - i + 1 < k) j++;
		else {
			ans.push_back(l.front());
			if (l.front() == a[i]) l.pop_front();
			i++; j++;
		}
	}
	return ans;
}
