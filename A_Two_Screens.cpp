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
    string s, t;
    cin >> s >> t;
    int d = 0;
    for (int i = 0; i < s.size() && i < t.size(); i++)
    {
        if (s[i] == t[i])
        {
            d = i + 1;
        }
        else
            break;
    }
    // cout<<"d="<<d<<endl;
    if (d == 0)
    {
        cout << s.size() + t.size() << endl;
        return;
    }
    int ans = d + 1 + s.size() - d + t.size() - d;
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