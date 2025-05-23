#include <bits/stdc++.h>

using namespace std;

#define ll            long long
// #define int ll
#define pii           pair< int, int >
#define all(x)        x.begin(), x.end()
#define endl          '\n'
#define fer(i, m, n)  for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i >= n; --i)
#define inf           INT_MAX

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;
    vector< int > arr(n);
    fer(i, 0, n) cin >> arr[i];

    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i += 2)
        s1 += arr[i];
    for (int i = 1; i < n; i += 2)
        s2 += arr[i];
    int c1 = (n + 1) / 2, c2 = n - c1;
    if((s1 + s2) % n || s1 % c1 || s2 % c2){cout << "NO" << '\n';return;}
    if ((s1 + s2) * 1.0 / n != s1 * 1.0 / c1 || s1 * 1.0 / c1 != s2 * 1.0 / c2)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}