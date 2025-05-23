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
    vector<int> arr(n);
    map<int, int> mp;

    fer(i, 0, n) cin >> arr[i];
        
    
    auto ok = [&]() -> bool {
        return mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 &&
            mp[3] >= 1 && mp[5] >= 1;
    };

    fer(i, 0, n) {
        mp[arr[i]]++;
        if(ok()) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}