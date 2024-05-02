/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()

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
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ds.unite(u, v);
	}
	set<int> par;
	for (int i = 1; i <= n; i++) {
		par.insert(ds.getPar(i));
	}
	int firstComp = *par.begin();
	par.erase(par.begin());
	cout << (int)par.size() << '\n';
	for (auto& x : par) {
		cout << firstComp << ' ' << x << '\n';
	}
	return 0;
}