class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        int sqrtN = sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        long long sa = 0, sb = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (isPrime(i)) {
                sa += nums[i];
            } else {
                sb += nums[i];
            }
        }
        return abs(sa - sb);
    }
};