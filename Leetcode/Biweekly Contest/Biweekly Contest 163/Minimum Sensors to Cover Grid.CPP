class Solution {
public:
	int minSensors(int n, int m, int k) {
		int step = 2 * k + 1;
		int rows = (n + step - 1) / step;
		int cols = (m + step - 1) / step;
		return rows * cols;
	}
};