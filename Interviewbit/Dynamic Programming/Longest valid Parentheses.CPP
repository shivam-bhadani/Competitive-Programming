// Problem Link - https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(i);
        else {
            if (st.empty()) continue;
            int j = st.top();
            st.pop();
            dp[i] = i - j + 1 + (j - 1 >= 0 ? dp[j - 1] : 0);
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}
