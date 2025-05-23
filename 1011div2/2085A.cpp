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
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if(s[i] >= s[j]) cnt++;
        if(cnt > k) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}