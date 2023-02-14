// Problem Link - https://www.interviewbit.com/problems/knight-on-chess-board/

struct Data {
    int x, y, step;
    Data(int _x, int _y, int _s) {
        x = _x;
        y = _y;
        step = _s;
    }
};

int Solution::knight(int n, int m, int sx, int sy, int destx, int desty) {
    vector<vector<int>> vis(n + 5, vector<int>(m + 5));
    queue<Data> q;
    q.push(Data(sx, sy, 0));
    vis[sx][sy] = 1;
    int dx[] = { -2, -1, +1, +2, +2, +1, -1, -2};
    int dy[] = { +1, +2, +2, +1, -1, -2, -2, -1};
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop();
        if (x == destx && y == desty) {
            return step;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push(Data(nx, ny, step + 1));
            }
        }
    }
    return -1;
}
