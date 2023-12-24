class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(30, vector<long long>(30, INT_MAX));
        for (int i = 0; i < (int)original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (i == j) dist[i][j] = 0;
                    if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < (int)source.size(); i++) {
            if (dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};