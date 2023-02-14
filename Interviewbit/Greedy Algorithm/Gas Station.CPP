// Problem Link - https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
	int fuel = 0, start_i = 0, sum = 0;

	for (int i = 0; i < gas.size(); i++) {
		sum = sum + (gas[i] - cost[i]);
		fuel = fuel + (gas[i] - cost[i]);
		if (fuel < 0) {
			fuel = 0;
			start_i = i + 1;
		}
	}

	if (sum >= 0) {
		return start_i % (gas.size());
	}

	return -1;
}
