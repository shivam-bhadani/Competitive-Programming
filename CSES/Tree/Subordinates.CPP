/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 200005;

vector<int> adj[N];
vector<int> sub_ordinate(N);

void dfs(int node, int par) {
	sub_ordinate[node] = 1;
	for (auto& it : adj[node]) {
		if (it == par) continue;
		dfs(it, node);
		sub_ordinate[node] += sub_ordinate[it];
	}
}

int main() {
	IOS
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << sub_ordinate[i] - 1 << ' ';
	}
}