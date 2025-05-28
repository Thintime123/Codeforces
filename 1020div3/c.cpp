#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    fer(i, 0, n) cin >> a[i];
    fer(i, 0, n) cin >> b[i];

    int s = -1;
    fer(i, 0, n) {
        if(b[i] != -1) {
            if(s == -1) s = a[i] + b[i];
            else if(s != a[i] + b[i]) {
                cout << 0 << '\n';
                return;
            }
        }
    }
    if(s != -1) {
        int m = s - *min_element(all(a)), n = s - *max_element(all(a));
        if(m <= k && n >= 0) {
            cout << 1 << '\n';
            return;
        } else {
            cout << 0 << '\n';
            return;
        }
    } else {
        int m = *max_element(all(a)), n = *min_element(all(a)) + k;
        cout << n - m + 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}