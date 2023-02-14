// Problem Link - https://www.interviewbit.com/problems/min-cost-path/

int Solution::solve(int n, int m, vector<string> &C) {
    vector<vector<int>> dis(n + 5, vector<int>(m + 5, INT_MAX));
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 0;
    int ans = INT_MAX;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int nx = x, ny = y;
        if (C[x][y] == 'U') nx--;
        if (C[x][y] == 'D') nx++;
        if (C[x][y] == 'L') ny--;
        if (C[x][y] == 'R') ny++;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[nx][ny] > dis[x][y]) {
            dis[nx][ny] = dis[x][y];
            q.push({nx, ny});
        }
        if (x + 1 >= 0 && x + 1 < n) {
            int nxt_dis = dis[x][y] + (C[x][y] != 'D');
            if (dis[x + 1][y] > nxt_dis) {
                dis[x + 1][y] = nxt_dis;
                q.push({x + 1, y});
            }
        }
        if (y + 1 >= 0 && y + 1 < m) {
            int nxt_dis = dis[x][y] + (C[x][y] != 'R');
            if (dis[x][y + 1] > nxt_dis) {
                dis[x][y + 1] = nxt_dis;
                q.push({x, y + 1});
            }
        }
        if (x - 1 >= 0 && x - 1 < n) {
            int nxt_dis = dis[x][y] + (C[x][y] != 'U');
            if (dis[x - 1][y] > nxt_dis) {
                dis[x - 1][y] = nxt_dis;
                q.push({x - 1, y});
            }
        }
        if (y - 1 >= 0 && y - 1 < m) {
            int nxt_dis = dis[x][y] + (C[x][y] != 'L');
            if (dis[x][y - 1] > nxt_dis) {
                dis[x][y - 1] = nxt_dis;
                q.push({x, y - 1});
            }
        }
    }
    return dis[n - 1][m - 1];
}
