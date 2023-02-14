// Problem Link - https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &nums) {
	int n = nums.size(), cnt = 0, ele;
	for (int i = 0; i < n; i++) {
		if (cnt == 0) ele = nums[i];
		if (ele == nums[i]) cnt++;
		else cnt--;
	}
	return ele;
}
