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

    if(k & 1) {
    	fer(i, 0, n - 1) cout << n << ' ';
    	cout << n - 1 << '\n';
    }
    else {
    	fer(i, 0, n - 2) cout << n - 1 << ' ';
    	cout << n << ' ' << n - 1 << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}