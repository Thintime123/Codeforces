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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    fer(i, 0, n) cin >> arr[i];

    int s = accumulate(all(arr), 0);
    if(s % n == 0 && s / n == x) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}