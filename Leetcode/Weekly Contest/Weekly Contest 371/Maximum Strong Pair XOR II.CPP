class Solution {
public:
    struct trie {
        trie* next[2];
        trie() {
            next[0] = NULL;
            next[1] = NULL;
        }
    };

    class TrieNode {
    private:
        trie* root;

    public:
        TrieNode() {
            root = new trie();
        }

        void insert(int num) {
            trie* curr = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (curr->next[bit] == NULL) {
                    curr->next[bit] = new trie();
                }
                curr = curr->next[bit];
            }
        }

        int max_xor(int num) {
            trie* curr = root;
            int ans = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (curr->next[!bit]) {
                    ans += (1 << i);
                    curr = curr->next[!bit];
                } else {
                    curr = curr->next[bit];
                }
            }
            return ans;
        }

        bool removeHelper(trie*& node, int key, int depth) {
            if (node == NULL) {
                return false;
            }
            if (depth == -1) {
                delete node;
                node = NULL;
                return true;
            }

            int bit = (key >> depth) & 1;
            bool shouldRemoveChild = removeHelper(node->next[bit], key, depth - 1);

            if (shouldRemoveChild) {
                delete node->next[bit];
                node->next[bit] = NULL;
            }
            return node->next[0] == NULL && node->next[1] == NULL;
        }

        void remove(int key) {
            removeHelper(root, key, 31);
        }
    };

    int maximumStrongPairXor(vector<int>& nums) {
        TrieNode* trieNode = new TrieNode();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int ans = 0;
        while (i < nums.size()) {
            while (j < nums.size() && nums[j] - nums[i] <= nums[i]) {
                trieNode->insert(nums[j]);
                ++j;
            }
            trieNode->insert(nums[i]);
            ans = max(ans, trieNode->max_xor(nums[i]));
            trieNode->remove(nums[i]);
            ++i;
        }
        return ans;
    }
};
