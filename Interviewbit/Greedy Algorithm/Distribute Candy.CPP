// Problem Link - https://www.interviewbit.com/problems/distribute-candy/

int Solution::candy(vector<int> &a) {
    int n = a.size();
    vector<int> lft(n, 1);
    vector<int> rght(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            lft[i] = lft[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {
            rght[i] = rght[i + 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(lft[i], rght[i]);
    }
    return ans;
}
