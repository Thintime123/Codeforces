#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    fer(i, 1, n + 1) cin >> arr[i];

    int *dp = new int[n + 2];
    dp[0] = 0;
    fer(i, 1, n + 1) dp[i] = arr[i];

    int ans = 1e-9;
    fer(i, 1, n + 1)
    {
        if ((arr[i] + arr[i - 1]) & 1)
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
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