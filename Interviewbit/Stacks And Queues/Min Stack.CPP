// Problem Link - Min Stack

stack<long long> st;
long long curr_min;

MinStack::MinStack() {
	while (!st.empty()) {
		st.pop();
	}
}

void MinStack::push(int val) {
	if (st.empty()) {
		curr_min = val;
		st.push(val);
	}
	else if (curr_min <= val) {
		st.push(val);
	}
	else {
		long long temp = 2 * 1LL * val - curr_min;
		st.push(temp);
		curr_min = val;
	}
}

void MinStack::pop() {
	if (st.empty()) return;
	if (st.top() >= curr_min) {
		st.pop();
	}
	else {
		curr_min = 2 * 1LL * curr_min - st.top();
		st.pop();
	}
}

int MinStack::top() {
	if (st.empty()) return -1;
	if (st.top() >= curr_min) {
		return st.top();
	}
	else {
		return curr_min;
	}
}

int MinStack::getMin() {
	if (st.empty()) return -1;
	return curr_min;
}

