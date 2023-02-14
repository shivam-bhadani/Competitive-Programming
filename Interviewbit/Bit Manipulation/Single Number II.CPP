// Problem Link - https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &a) {
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        int cnt = 0;
        for (auto& x : a) {
            if ((1 << i) & x) {
                cnt++;
            }
        }
        cnt %= 3;
        ans = ans * 2 + cnt;
    }
    return ans;
}
