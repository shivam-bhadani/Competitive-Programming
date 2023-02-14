class Solution {
public:
    vector<int> vowelStrings(vector<string>& a, vector<vector<int>>& queries) {
        int n = a.size();
        vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        vector<long long> track(n + 5);
        for (int i = 0; i < n; i++) {
            if (count(vowel.begin(), vowel.end(), a[i][0]) && count(vowel.begin(), vowel.end(), a[i].back())) {
                track[i + 1] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            track[i] += track[i - 1];
        }
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0] + 1, r = q[1] + 1;
            long long now = track[r] - track[l - 1];
            ans.push_back(now);
        }
        return ans;
    }
};