/*
    Author: Shivam Bhadani
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

const int N = 2e5 + 5;
const int M = 30;

int table[N][M];

int main() {
	IOS
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> table[i][0];
	}
	for (int j = 1; j < M; j++) {
		for (int i = 1; i <= n; i++) {
			int intermidiate = table[i][j - 1];
			table[i][j] = table[intermidiate][j - 1];
		}
	}
	while (q--) {
		int x, k;
		cin >> x >> k;
		int node = x;
		for (int i = 0; i < M; i++) {
			if (k & (1 << i)) {
				node = table[node][i];
			}
		}
		cout << node << '\n';
	}
