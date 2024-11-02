#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

bool cmp(pii a, pii b){
    return a.second > b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pii>arr(k);
    fer(i, 0, k){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr));
    int ans = 0;
    fer(i, 0, n){
        ans += arr[i].second;
    }
    cout << ans << '\n';
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