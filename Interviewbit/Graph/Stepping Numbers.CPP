// Problem Link - https://www.interviewbit.com/problems/stepping-numbers/

vector<int> ans;

void solve(int x, int a, int b) {
    if (x > b) return;
    if (a <= x && x <= b) {
        ans.push_back(x);
    }
    int last = x % 10;
    if (last != 0) {
        solve(x * 10 + (last - 1), a, b);
    }
    if (last != 9) {
        solve(x * 10 + (last + 1), a, b);
    }
}

vector<int> Solution::stepnum(int a, int b) {
    ans.clear();
    if (a == 0) {
        ans.push_back(0);
    }
    for (int i = 1; i <= 9; i++) {
        solve(i, a, b);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
