#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

class Solution {
public:
    int greaterCount(ordered_multiset<int>& st, int k) {
        int less_equal_k = st.order_of_key(k + 1);
        return (int)st.size() - less_equal_k;
    }

    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dist(n);
        ordered_multiset<int> st1, st2;
        st1.insert(nums[0]);
        st2.insert(nums[1]);
        dist[0] = 1;
        dist[1] = 2;
        for (int i = 2; i < n; i++) {
            int c1 = greaterCount(st1, nums[i]);
            int c2 = greaterCount(st2, nums[i]);
            if (c1 > c2) {
                st1.insert(nums[i]);
                dist[i] = 1;
            }
            else if (c1 < c2) {
                st2.insert(nums[i]);
                dist[i] = 2;
            }
            else {
                if ((int)st1.size() <= (int)st2.size()) {
                    st1.insert(nums[i]);
                    dist[i] = 1;
                }
                else {
                    st2.insert(nums[i]);
                    dist[i] = 2;
                }
            }
        }
        vector<int> nums1, nums2;
        for (int i = 0; i < n; i++) {
            if (dist[i] == 1) {
                nums1.push_back(nums[i]);
            }
            else {
                nums2.push_back(nums[i]);
            }
        }
        vector<int> result = nums1;
        for (auto& x : nums2) {
            result.push_back(x);
        }
        return result;
    }
};