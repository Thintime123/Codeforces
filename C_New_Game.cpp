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
const int N = 1e5 + 2;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    map<int, int> mp;

    fer(i, n) cin >> arr[i], mp[arr[i]]++;
    sort(all(arr));
    // fer(i, n) cout << arr[i] << ' ';
    // cout << endl;
    int l = 0, ans = 1, t = 1, cnt = 1;
    ferr(i, n - 1)
    {
        if (arr[i] == arr[i - 1])
            t++;
        else if (arr[i] == arr[i - 1] + 1)
        {
            if (cnt < k)
                cnt++, t++;
            else
            {
                ans = max(ans, t);
                t = t - mp[arr[l]] + 1;
                l += mp[arr[l]];
            }
        }
        else
            ans = max(ans, t), l = i, t = 1, cnt = 1;
    }
    cout << max(ans, t) << endl;
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