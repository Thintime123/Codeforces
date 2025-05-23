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
    int n;
    cin >> n;
    if(n & 1) {
        for(int i = 1; i <= n; i += 2) cout << i << ' ';
        for(int i = 2; i <= n; i += 2) cout << i << ' ';
        cout << '\n';
    }
    else cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}