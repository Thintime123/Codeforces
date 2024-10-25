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

int s1[N][26], s2[N][26];

void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    a = " " + a, b = " " + b;
    fer(i, 1, n + 1)
    {
        s1[i][a[i] - 'a'] = s1[i - 1][a[i] - 'a'] + 1;
        s2[i][b[i] - 'a'] = s2[i - 1][a[i] - 'a'] + 1;
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;

        fer(i, 0, 26)
        {
            if (s1[r][i] - s1[l - 1][i] > s2[r][i] - s2[l - 1][i])
                ans += (s1[r][i] - s1[l - 1][i]) - (s2[r][i] - s2[l - 1][i]);
        }
        cout << ans << '\n';
    }
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