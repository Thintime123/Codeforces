#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, n) for (int i = 0; i < n; ++i)
#define ferr(i, n) for (int i = 1; i <= n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

ll fpow(int a, int b, int p)
{
    a %= p;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> s(n + 1);
    ferr(i, n) cin >> arr[i], s[i] = (s[i - 1] + arr[i]) % MOD;

    ll p = 0, q = n * (n - 1) / 2;
    for (int i = 1; i < n; i++)
        p = (p + arr[i] * (s[n] - s[i]) % MOD) % MOD;
    cout << p * fpow(q, MOD - 2, MOD) % MOD << endl;
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