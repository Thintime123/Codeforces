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
    cin >> n;
    int c = (n + 1) / 2;
    fer(i, 1, c + 1) cout << i << ' ';
    fer(i, c + 1, n + 1) cout << i << ' ';
    cout << '\n';

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