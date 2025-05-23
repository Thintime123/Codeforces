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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<int> dp(n + 2, -1); // 左岸为0， 右岸为n+1,
    dp[0] = k;                 // 初始化，在左岸时，可以游k米
    for (int i = 1; i <= n + 1; i++)
    {
        if (i != n + 1 && s[i - 1] == 'C') // 河中最后位置为鳄鱼，不能游，通过dp判断是否能跳过来
            continue;
        for (int t = 1; t <= m; t++) // dp算法，从当前为位置向左dp，dp长度为可以跳过的长度，算出当前位置还可以游几米
            if (i - t >= 0 && (i - t == 0 || s[i - t - 1] == 'L'))
                dp[i] = max(dp[i], dp[i - t]);
        if (i > 1 && s[i - 2] == 'W') // 此时位置的前一个位置为水时，判断是否需要游
            dp[i] = max(dp[i], dp[i - 1] - 1);
    }
    if (dp[n + 1] >= 0) // 不需要游k米时
        cout << "YES\n";
    else
        cout << "NO\n";
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