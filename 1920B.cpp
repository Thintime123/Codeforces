#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i > n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n + 1);
    int *s = new int[n + 1];
    s[0] = 0;

    fer(i, 1, n + 1) cin >> arr[i], s[i] = s[i - 1] + arr[i];

    int ans;
    fer(i, 0, k + 1)
    {
        int res = 0, l = min(x, n - i); // 可变号数量
        res = s[n - i] - 2 * (s[n - i] - s[n - i - l]);
        if (i == 0)
            ans = res;
        else
            ans = max(ans, res);
    }
    cout << ans << '\n';
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