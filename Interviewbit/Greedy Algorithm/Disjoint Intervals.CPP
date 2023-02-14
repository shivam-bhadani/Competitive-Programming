// Problem Link - https://www.interviewbit.com/problems/disjoint-intervals/

bool comp(vector<int>& x, vector<int>& y) {
    return x[0] < y[0];
}
int Solution::solve(vector<vector<int> > &a) {
    sort(a.begin(), a.end(), comp);
    int curr_mn = a[0][1];
    int ans = 1;
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (curr_mn < a[i][0]) {
            ans++;
            curr_mn = a[i][1];
        }
        else {
            curr_mn = min(curr_mn, a[i][1]);
        }
    }
    return ans;
}
