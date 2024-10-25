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
    vector<vector<int>> arr(n, vector<int>(n));
    //vector arr(n, vector<int>(n));
    map<int, int> mp;

    fer(i, 0, n)
    {
        fer(j, 0, n)
        {
            cin >> arr[i][j];
            if (arr[i][j] < 0)
            {
                mp[i - j] = max(-arr[i][j], mp[i - j]);
            }
        }
    }
    int ans = 0;
    for (auto it : mp)
        ans += it.second;
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