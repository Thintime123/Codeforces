#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, n) for (int i = 0; i < n; ++i)
#define ferr(i, n) for (int i = 1; i <= n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

ll fpow(ll a, ll b)
{
    ll ans = 1;
    // a %= p;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    while ((x & 1) == (y & 1))
    {
        cnt++;
        x >>= 1, y >>= 1;
    }
    cout << fpow(2, cnt) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}