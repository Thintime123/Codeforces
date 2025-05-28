#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int ptr = 0;
    for (int i = 0; i < n && ptr < m; ++i) {
        if (a[i] >= b[ptr]) {
            ptr++;
        }
    }
    if (ptr == m) {
        cout << 0 << endl;
        return;
    }

    vector<int> prefix(m + 1, -1);
    prefix[0] = -1;
    ptr = 0;
    for (int i = 0; i < n && ptr < m; ++i) {
        if (a[i] >= b[ptr]) {
            prefix[ptr + 1] = i;
            ptr++;
        }
    }

    vector<int> suffix(m + 1, -1);
    suffix[0] = n;
    ptr = m - 1;
    for (int i = n - 1; i >= 0 && ptr >= 0; --i) {
        if (a[i] >= b[ptr]) {
            suffix[m - ptr] = i;
            ptr--;
        }
    }

    int min_k = -1;
    for (int x = 0; x <= m; ++x) {
        int y = m - x - 1;
        if (x > 0 && prefix[x] == -1) continue;
        if (y > 0 && suffix[y] == -1) continue;
        int left_pos = (x == 0) ? -1 : prefix[x];
        int right_pos = (y == 0) ? n : suffix[y];
        if (left_pos < right_pos) {
            int required_k = b[x];
            if (min_k == -1 || required_k < min_k) {
                min_k = required_k;
            }
        }
    }

    cout << min_k << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}