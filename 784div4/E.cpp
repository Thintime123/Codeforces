#include<bits/stdc++.h>
#include <vector>

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
    int n;
    cin >> n;

    int mp[20][20]{};
    vector<string>arr(n);
    fer(i, 0, n) cin >> arr[i], mp[arr[i][0] - 'a'][arr[i][1] - 'a']++;

    ll ans = 0;
    fer(i, 0, n){
        fer(j, 0, 11){
            if(arr[i][1] - 'a' != j) ans += mp[arr[i][0] - 'a'][j];
            if(arr[i][0] - 'a' != j) ans += mp[j][arr[i][1] - 'a'];
        }
    }
    cout << ans / 2 << '\n';
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