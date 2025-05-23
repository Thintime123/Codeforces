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
    int n;
    string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;

    fer(i, s.size())
    {
        if (s[i] == '0')
        {
            if (i == s.size() - 1)
                c0++;
            int j = i + 1;
            for (j = i + 1; j < s.size(); ++j)
            {
                if (s[j] != '0' || j == s.size() - 1 && s[j] == '0')
                {
                    c0++;
                    if (s[j] == '1')
                        c1++;
                    break;
                }
            }
            i = j;
        }
        else
            c1++;
    }
    cout << (c1 > c0 ? "YES" : "NO") << endl;
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