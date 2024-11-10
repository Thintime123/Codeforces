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


void solve() {
    int n;
    ll a = 1;
    cin >> n;
    vector<int>arr;
    fer(i, 0, n){
        ll a0;
        cin >> a0;
        if(a0 & 1) a = max(a, a0);
        else arr.push_back(int(a0));
    }

    if(arr.size() == n){
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    sort(all(arr));
    for(auto c : arr){
        if(c < a) ans++, a += c;
        else{
            ans += 2;
            a += c;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start_time = clock();

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

#ifdef LOCAL
    cout << "\nTime : ";
    cout << (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms\n";
#endif
    return 0;
}