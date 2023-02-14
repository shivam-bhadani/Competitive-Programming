// Problem Link -https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

string Solution::solve(string s) {
	queue<char> q;
	map<char, int> mp;
	string ans;
	for (auto& c : s) {
		mp[c]++;
		q.push(c);
		while (!q.empty() && mp[q.front()] >= 2) q.pop();
		if (q.empty()) {
			ans.push_back('#');
		}
		else ans.push_back(q.front());
	}
	return ans;
}
