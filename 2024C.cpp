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

bool cmp(pii p1, pii p2)
{
    return (p1.first + p1.second) / 2.0 < (p2.first + p2.second) / 2.0;
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> arr;
    fer(i, n)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(all(arr), [&](pii p1, pii p2)
         { return (p1.first + p1.second) / 2.0 < (p2.first + p2.second) / 2.0; });

    fer(i, n)
    {
        cout << arr[i].first << ' ' << arr[i].second << ' ';
    }
    cout << '\n';
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