/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define all(x) x.begin(), x.end()
#define nline '\n'

void run_case()
{
	int rs, rh;
	cin >> rs >> rh;
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto& x : a) {
		cin >> x.first >> x.second;
	}
	int m;
	cin >> m;
	vector<pair<int, int>> b(m);
	for (auto& x : b) {
		cin >> x.first >> x.second;
	}
	vector<double> red, yellow;
	for (auto& x : a) {
		double centre_dis = sqrt((x.first * x.first) + (x.second * x.second));
		if (centre_dis <= (rs + rh)) {
			red.push_back(centre_dis);
		}
	}
	for (auto& x : b) {
		double centre_dis = sqrt((x.first * x.first) + (x.second * x.second));
		if (centre_dis <= (rs + rh)) {
			yellow.push_back(centre_dis);
		}
	}
	sort(all(red));
	sort(all(yellow));
	if (yellow.size() == 0) {
		cout << red.size() << " 0" << nline;
	}
	else if (red.size() == 0) {
		cout << "0 " << yellow.size() << nline;
	}
	else {
		int ans_r = 0, ans_y = 0;
		int i = 0;
		while (i < red.size() && red[i] < yellow[0]) {
			ans_r++;
			++i;
		}
		i = 0;
		while (i < yellow.size() && yellow[i] < red[0]) {
			ans_y++;
			++i;
		}
		cout << ans_r << ' ' << ans_y << nline;
	}
}

int32_t main() {
	IOS
	int test_cases;
	cin >> test_cases;
	for (int test_id = 1; test_id <= test_cases; test_id++) {
		cout << "Case #" << test_id << ": ";
		run_case();
	}
	return 0;
}