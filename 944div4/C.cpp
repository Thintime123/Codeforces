#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define inf INT_MAX

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(c > d) swap(c, d);
    bool ok = false;
    if(a > c && a < d && (b < c || b > d)) ok = true;
    else if(b > c && b < d && (a < c || a > d)) ok = true;

    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}