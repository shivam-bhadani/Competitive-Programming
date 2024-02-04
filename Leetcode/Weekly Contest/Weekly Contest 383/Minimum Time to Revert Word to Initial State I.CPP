class Solution {
public:
    int check(int i, string& word) {
        int j = 0;
        while (i < word.size()) {
            if (word[i] != word[j]) return 0;
            ++i;
            ++j;
        }
        return 1;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int ans = (n + k - 1) / k;
        for (int i = 1; i <= n / k; i++) {
            int i1 = i * k;
            if (check(i1, word)) {
                return i;
            }
        }
        return ans;
    }
};