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

bool is_prime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= n / i; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;

    if(k == 1) {
        cout << (is_prime(n) ? "YES" : "NO") << '\n';
    } else {
        if(n == 1 && k == 2) cout << "YES" << '\n';
        else cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}