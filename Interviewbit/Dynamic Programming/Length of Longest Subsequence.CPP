// Problem Link - https://www.interviewbit.com/problems/length-of-longest-subsequence/

int Solution::longestSubsequenceLength(const vector<int> &a) {
    int n = a.size();
    vector<int> dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp1[i] = max(dp1[i], 1 + dp1[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return ans;
}
