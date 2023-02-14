class Solution {
public:
	bool makeStringsEqual(string s, string target) {
		if (s == target) return true;
		int ones = count(s.begin(), s.end(), '1');
		int onet = count(target.begin(), target.end(), '1');
		if (onet && ones) return true;
		return false;
	}
};