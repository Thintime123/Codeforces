#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
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
    fer(i, 0, n) cin >> arr[i];

    map<int, int> mp;
    for(int x : arr) mp[x]++;
    for(auto [x, cnt] : mp) {
        if(cnt == 1) {
            cout << 1 << '\n';
            return;
        }
    }

    int cnt = 0, ans = 1;
    set<int> st1, st2;
    fer(i, 0, n) {
        if(i == 0) {
            st1.insert(arr[i]), mp[arr[i]]--;
            if(mp[arr[i]] == 0) break;
            continue;
        }
        st2.insert(arr[i]), mp[arr[i]]--;
        if(st1.count(arr[i])) cnt++;
        if(cnt == st1.size()) {
            ans++;
            if(mp[arr[i]] == 0) break;
            st1 = st2, st2.clear();
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