class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int p = (nums[0] & 1);
        for(auto& x: nums) {
            if((x & 1) != p) {
                return false;
            }
            p ^= 1;
        }
        return true;
    }
};