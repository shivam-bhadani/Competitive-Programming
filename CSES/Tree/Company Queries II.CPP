/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 2e5 + 5;

vector<int> adj[N];

class BinaryLifting {
public:
	ll n;
	ll mxLog;
	ll ID = -1;
	vector<vector<ll>> table;

	BinaryLifting(ll s) {
		n = s;
		mxLog = log2(n + 1);
		table.resize(n + 5);
		for (int i = 0; i <= n + 1; i++) {
			table[i].assign(mxLog + 1, ID);
		}
	}

	void build(int root) {
		dfsBL(root, -1);
		for (int i = 1; i <= mxLog; i++) {
			for (int j = 1; j <= n; j++) {
				int intermidiate = table[j][i - 1];
				if (intermidiate != ID) {
					table[j][i] = table[intermidiate][i - 1];
				}
			}
		}
	}

	void dfsBL(int node, int par) {
		for (auto& it : adj[node]) {
			if (it == par) continue;
			table[it][0] = node;
			dfsBL(it, node);
		}
	}

	int kthParent(int node, int k) {
		for (int i = 0; i <= mxLog; i++) {
			if (k & (1 << i)) {
				node = table[node][i];
				if (node == ID) return node;
			}
		}
		return node;
	}
};

class LCA {
public:
	ll n;
	vector<ll> level;

	LCA(ll s) {
		n = s;
		level.resize(n + 5);
	}

	void init(int root) {
		dfsLCA(root, -1);
	}

	void dfsLCA(int node, int par) {
		for (auto& it : adj[node]) {
			if (it == par) continue;
			level[it] = 1 + level[node];
			dfsLCA(it, node);
		}
	}

	int getLCA(int a, int b, BinaryLifting& bl) {
		if (level[a] > level[b]) {
			swap(a, b);
		}
		b = bl.kthParent(b, level[b] - level[a]);
		if (a == b) return a;
		for (int i = bl.mxLog; i >= 0; i--) {
			int p1 = bl.table[a][i];
			int p2 = bl.table[b][i];
			if (p1 != p2 && p1 != -1 && p2 != -1) {
				a = p1;
				b = p2;
			}
		}
		return bl.table[a][0];
	}
};

int main() {
	IOS
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	BinaryLifting bl(n);
	bl.build(1);
	LCA lca(n);
	lca.init(1);
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << lca.getLCA(a, b, bl) << '\n';
	}
}