// Problem Link - https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string a) {
	stack<char> st;
	for (auto& c : a) {
		if (c != ')') st.push(c);
		else {
			int f = 1;
			while (st.top() != '(') {
				char x = st.top();
				if (x == '+' || x == '-' || x == '*' || x == '/') f = 0;
				st.pop();
			}
			st.pop();
			if (f) return 1;
		}
	}
	return 0;
}
