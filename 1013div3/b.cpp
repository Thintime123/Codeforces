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
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    fer(i, 0, n) cin >> arr[i];

    ll ans = 0;
    sort(all(arr), greater());
    int cnt = 0;

    ll t = x;
    fer(i, 0, n) {
        if(arr[i] >= x) {
            ans++;
            continue;
        }
        t = min(t, arr[i]), cnt++;
        if(t * cnt >= x) {
            ans++;
            t = x, cnt = 0;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}