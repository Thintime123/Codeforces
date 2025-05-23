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

    fer(i, 2, n / 2 + 1)
    {
        int pre = (arr[i] == arr[i - 1]) + (arr[n - i + 1] == arr[n - i + 2]);
        int nex = (arr[i] == arr[n - i + 2]) + (arr[i - 1] == arr[n - i + 1]);
        if (pre > nex)
            swap(arr[i], arr[n - i + 1]);
    }
    int ans = 0;
    fer(i, 2, n + 1)
    {
        if (arr[i] == arr[i - 1])
            ans++;
    }
    cout << ans << endl;
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