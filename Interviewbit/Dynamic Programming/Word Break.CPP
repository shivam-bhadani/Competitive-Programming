// Problem Link - https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string s, vector<string> &B) {
    int n = s.size();
    vector<int> dp(n + 5);
    dp[n] = 1;
    set<string> st;
    for (auto& s : B) {
        st.insert(s);
    }
    for (int i = n - 1; i >= 0; i--) {
        string pref;
        for (int j = i; j < s.size(); j++) {
            pref.push_back(s[j]);
            if (st.count(pref)) {
                dp[i] |= dp[j + 1];
            }
            if (dp[i]) break;
        }
    }
    return dp[0];
}
