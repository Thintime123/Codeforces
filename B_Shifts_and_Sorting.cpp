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
    string s;
    cin >> s;
    int ans = 0;
    int ind = -1;
    fer(i, s.size()) if (s[i] == '1')
    {
        ind = i;
        break;
    }
    if (ind == -1)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = ind + 1; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            ans += i - ind + 1;
            ind++;
        }
    }
    cout << ans << endl;
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