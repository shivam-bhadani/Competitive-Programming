// Problem Link - https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/

struct Color {
    int x, y, z;
    Color(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};

int Solution::solve(int n) {
    vector<Color> fillComb;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (i != j && j != k)
                    fillComb.push_back(Color(i, j, k));
            }
        }
    }
    int dp[n + 5][4][4][4];
    memset(dp, 0, sizeof dp);
    for (Color& i : fillComb) {
        dp[1][i.x][i.y][i.z] = 1;
    }
    const int MOD = 1e9 + 7;
    for (int i = 2; i <= n; i++) {
        for (auto& it1 : fillComb) {
            for (auto& it2 : fillComb) {
                if (it1.x != it2.x && it1.y != it2.y && it1.z != it2.z) {
                    dp[i][it1.x][it1.y][it1.z] = (dp[i][it1.x][it1.y][it1.z] + dp[i - 1][it2.x][it2.y][it2.z]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (auto& it : fillComb) {
        ans = (ans + dp[n][it.x][it.y][it.z]) % MOD;
    }
    return ans;
}
