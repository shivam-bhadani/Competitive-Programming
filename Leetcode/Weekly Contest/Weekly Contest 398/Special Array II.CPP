class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> odd_pos_odd, odd_pos_evn, evn_pos_odd, evn_pos_evn;
        for(int i=0; i<n; i++) {
            if(nums[i] & 1) {
                if(i & 1) odd_pos_odd.push_back(i);
                else evn_pos_odd.push_back(i);
            }
            else {
                if(i & 1) odd_pos_evn.push_back(i);
                else evn_pos_evn.push_back(i); 
            }
        }
        vector<bool> ans;
        for(auto& x: queries) {
            int l = x[0], r = x[1];
            bool now = true;
            if(nums[l] & 1) {
                if(l & 1) {
                    auto it1 = lower_bound(evn_pos_odd.begin(), evn_pos_odd.end(), l);
                    if(it1 != evn_pos_odd.end() && *it1 <= r) {
                        now = false;
                    }
                    auto it2 = lower_bound(odd_pos_evn.begin(), odd_pos_evn.end(), l);
                    if(it2 != odd_pos_evn.end() && *it2 <= r) {
                        now = false;
                    }
                }
                else {
                    auto it1 = lower_bound(evn_pos_evn.begin(), evn_pos_evn.end(), l);
                    if(it1 != evn_pos_evn.end() && *it1 <= r) {
                        now = false;
                    }
                    auto it2 = lower_bound(odd_pos_odd.begin(), odd_pos_odd.end(), l);
                    if(it2 != odd_pos_odd.end() && *it2 <= r) {
                        now = false;
                    }
                }
            }
            else {
                if(l & 1) {
                    auto it1 = lower_bound(evn_pos_evn.begin(), evn_pos_evn.end(), l);
                    if(it1 != evn_pos_evn.end() && *it1 <= r) {
                        now = false;
                    }
                    auto it2 = lower_bound(odd_pos_odd.begin(), odd_pos_odd.end(), l);
                    if(it2 != odd_pos_odd.end() && *it2 <= r) {
                        now = false;
                    }
                }
                else {
                    auto it1 = lower_bound(evn_pos_odd.begin(), evn_pos_odd.end(), l);
                    if(it1 != evn_pos_odd.end() && *it1 <= r) {
                        now = false;
                    }
                    auto it2 = lower_bound(odd_pos_evn.begin(), odd_pos_evn.end(), l);
                    if(it2 != odd_pos_evn.end() && *it2 <= r) {
                        now = false;
                    }
                }
            }
            ans.push_back(now);
        }
        return ans;
    }
};