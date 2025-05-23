#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

int dis(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pii> arr(n + 2);

    fer(i, 1, n + 1) cin >> arr[i].first >> arr[i].second;

    int ans = dis(arr[a], arr[b]);
    int d1 = ans, d2 = ans;
    fer(i, 1, k + 1)
    {
        d1 = min(d1, dis(arr[a], arr[i]));
        d2 = min(d2, dis(arr[b], arr[i]));
    }
    cout << min(ans, d1 + d2) << '\n';
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