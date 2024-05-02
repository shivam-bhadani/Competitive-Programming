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

const int N = 505;

ll dis[N][N];

int main() {
	IOS
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = LLONG_MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[v][u], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << (dis[a][b] == LLONG_MAX ? -1 : dis[a][b]) << '\n';
	}
	return 0;
}