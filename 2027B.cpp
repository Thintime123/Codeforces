#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    queue<int> q;

    int mx = 0, cnt = 1, cntmx = 1;
    fer(i, 0, n)
    {
        cin >> arr[i];
        if (i == 0)
        {
            mx = arr[i];
            q.push(mx);
            continue;
        }
        if (arr[i] > mx)
            mx = arr[i], q.push(mx), cnt = 1;
        else if (arr[i] == mx)
        {
            q.push(mx);
            cnt++;
            cntmx = max(cntmx, cnt);
        }
    }

    int ans = q.size() - cntmx;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start_time = clock();

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

#ifdef LOCAL
    cout << "\nTime : ";
    cout << (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms\n";
#endif
    return 0;
}