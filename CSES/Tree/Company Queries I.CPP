/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

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

int main() {
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
	while (q--) {
		int x, k;
		cin >> x >> k;
		cout << bl.kthParent(x, k) << '\n';
	}
}