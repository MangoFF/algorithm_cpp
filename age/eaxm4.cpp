#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solve(string s) {
    int n = s.length();
    stack<int> stk;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (stk.empty() || stk.top() == 0) {
                stk.push(1);
            } else {
                int len = stk.top();
                stk.pop();
                len++;
                stk.push(len);
            }
        } else {
            stk.push(0);
        }
    }

    while (!stk.empty()) {
        int len = stk.top();
        stk.pop();
        ans += (len > 0);
    }

    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
