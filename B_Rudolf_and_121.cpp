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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    fer(i, n) cin >> arr[i];

    for (int i = 1; i <= n - 2; i++)
    {
        arr[i] -= 2 * arr[i - 1];
        arr[i - 1] = 0;
        arr[i + 1] -= arr[i - 1];

        if (arr[i - 1] < 0 || arr[i] < 0 || arr[i + 1] < 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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