// Problem Link - https://www.interviewbit.com/problems/meeting-rooms/

bool comp(pair<int, char>& a, pair<int, char>& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}
int Solution::solve(vector<vector<int> > &a) {
	vector<pair<int, char>> track;
	for (auto& x : a) {
		track.push_back({x[0], 'a'});
		track.push_back({x[1], 'd'});
	}
	sort(track.begin(), track.end(), comp);
	int ans = 0, curr = 0;
	for (auto& x : track) {
		if (x.second == 'a') curr++;
		else curr--;
		ans = max(ans, curr);
	}
	return ans;
}
