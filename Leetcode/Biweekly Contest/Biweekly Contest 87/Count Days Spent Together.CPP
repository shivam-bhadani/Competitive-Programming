class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int s1 = 0;
        int m = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
        int d = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
        for (int i = 1; i < m; i++) {
            s1 += days[i - 1];
        }
        s1 += d;
        int e1 = 0;
        m = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
        d = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
        for (int i = 1; i < m; i++) {
            e1 += days[i - 1];
        }
        e1 += d;
        int s2 = 0;
        m = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
        d = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
        for (int i = 1; i < m; i++) {
            s2 += days[i - 1];
        }
        s2 += d;
        int e2 = 0;
        m = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
        d = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');
        for (int i = 1; i < m; i++) {
            e2 += days[i - 1];
        }
        e2 += d;
        if (s1 > s2) {
            swap(s1, s2);
            swap(e1, e2);
        }
        if (e1 < s2) return 0;
        return min(e1 - s2 + 1, e2 - s2 + 1);
    }
};