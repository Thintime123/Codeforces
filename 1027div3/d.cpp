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
    vector<pii> arr(n);

    vector<int> px(n), py(n);
    fer(i, 0, n) {
        cin >> arr[i].first >> arr[i].second;
        px[i] = arr[i].first, py[i] = arr[i].second;
    }
    sort(all(px)), sort(all(py));

    int min_x = px[0], max_x = px[n - 1];
    int min_y = py[0], max_y = py[n - 1];
    int cxmin = 1, cxmax = 1, cymin = 1, cymax = 1;

    fer(i, 1, n) {
        if(px[i] == min_x) cxmin++;
        else break;
    }
    ferd(i, n - 2, 0) {
        if(px[i] == max_x) cxmax++;
        else break;
    }
    fer(i, 1, n) {
        if(py[i] == min_y) cymin++;
        else break;
    }
    ferd(i, n - 2, 0) {
        if(py[i] == max_y) cymax++;
        else break;
    }
    ll ans = 1LL * (max_x - min_x + 1) * (max_y - min_y + 1);
    ll res = ans;

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    if(n == 2) {
        cout << 1 << '\n';
        return;
    }
    if(cxmin == 1) {
        res = 1LL * (max_x - px[1] + 1) * (max_y - min_y + 1);
        ans = min(ans, res);
    }
    if(cxmax == 1) {
        res = 1LL * (px[n - 2] - min_x + 1) * (max_y - min_y + 1);
        ans = min(ans, res);
    }
    if(cymin == 1) {
        res = 1LL * (max_x - min_x + 1) * (max_y - py[1] + 1);
        ans = min(ans, res);
    }
    if(cymax == 1) {
        res = 1LL * (max_x - min_x + 1) * (py[n - 2] - min_y + 1);
        ans = min(ans, res);
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