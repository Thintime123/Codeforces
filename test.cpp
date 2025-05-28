#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << '=' << ' ' << x << '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
const int inf = 1e9;

int f(int n) {
    int cnt = 0;
    for(int i = 1; i <= n / i; ++i) {
        if(n % i == 0) {
            cnt += 2;
            if(i * i == n) {
                cnt--;
            }
        }
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int ans = 0;
    fer(i, 1, 1e6 + 1) {
        ans = max(ans, f(i));
    }
    cout << ans << '\n';
    return 0;
}