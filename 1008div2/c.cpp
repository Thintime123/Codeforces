#include<bits/stdc++.h>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cerr << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;


void solve() {
    int n;
    cin >> n;
    vector<int> b(2 * n);

    fer(i, 0, 2 * n) cin >> b[i];
    sort(all(b), greater<>());

    ll k = 0;
    fer(i, 2, n + 1) k -= b[i];
    fer(i, n + 1, 2 * n) k += b[i];
    ll x = b[0] + b[1] - k;
    dbg(k);
    cout << b[0] << ' ' << x << ' ' << b[1] << ' ';
    fer(i, 2, n + 1) cout << b[n - 1 + i] << ' ' << b[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}