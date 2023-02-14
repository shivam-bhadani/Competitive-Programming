// Problem Link - https://www.interviewbit.com/problems/max-product-subarray/

int Solution::maxProduct(const vector<int> &nums) {
    int n = nums.size();
    int ans = INT_MIN, pro = 1;
    for (int i = 0; i < n; i++) {
        pro *= nums[i];
        ans = max(ans, pro);
        if (pro == 0) pro = 1;
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--) {
        pro *= nums[i];
        ans = max(ans, pro);
        if (pro == 0) pro = 1;
    }
    return ans;
}
