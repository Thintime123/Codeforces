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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    fer(i, n) cin >> arr[i];
    sort(all(arr));
    int mn = arr[0];
    int ans = 0;
    int s = 0; // 需要减的数

    int c = 0; // 开始计数的下标
    int t = 0;
    while (c < n)
    {
        if (ans >= k)
            break;
        s += arr[c];
        if (ans + mn * (n - c) <= k)
            ans += mn * (n - c);
        else
        {
            int cnt = ceil((k - ans) * 1.0 / (n - c));
            ans += mn * cnt;
        }
        bool f = false;
        for (int i = c; i < n; i++)
        {
            if (arr[i] - s > 0)
            {
                c = i;
                f = true;
                mn = arr[i] - s;
                t = c;
                break;
            }
        }
        if (!f)
            break;
    }

    cout << ans + t << '\n';
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