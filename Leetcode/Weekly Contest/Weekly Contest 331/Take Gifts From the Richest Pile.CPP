class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for (auto& x : gifts) {
            pq.push(x);
        }
        long long ans = 0;
        while (k--) {
            long long x = pq.top();
            pq.pop();
            long long now = sqrt(x);
            pq.push(now);
        }
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};