/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

class DSU
{
private:
	vector<int> parent, size;
public:
	DSU(int n)
	{
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}
	int getPar(int node)
	{
		if (parent[node] == node)
			return node;
		return parent[node] = getPar(parent[node]);
	}
	void unite(int u, int v)
	{
		int pu = getPar(u);
		int pv = getPar(v);
		if (pu == pv)
			return;
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}
	int siz(int n)
	{
		int p = getPar(n);
		return size[p];
	}
};

int main() {
	IOS
	int n, m;
	cin >> n >> m;
	DSU ds(n + 5);
	int connComp = n, mxSizeComp = 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (ds.getPar(u) != ds.getPar(v)) {
			--connComp;
			ds.unite(u, v);
		}
		mxSizeComp = max(mxSizeComp, ds.siz(u));
		cout << connComp << ' ' << mxSizeComp << '\n';
	}
}