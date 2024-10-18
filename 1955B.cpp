#include <bits/stdc++.h>
#include<unordered_map>

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
    int n, c, d;
    cin >> n >> c >> d;
    unordered_map<int, int> mp;

    int mn = 1e9;
    fer(i, n * n)
    {
        int a;
        cin >> a;
        mn = min(mn, a);
        mp[a]++;
    }
    int a1 = mn, a2, a3;
    if (mp[a1 + d] && mp[a1 + 2 * d])
    {
        a2 = a1 + d, a3 = a2 + d;
        mp[a1]--, mp[a2]--, mp[a3]--;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (mp[a1 + c] && mp[a2 + c] && mp[a3 + c])
        {
            a1 += c, a2 += c, a3 += c;
            mp[a1]--, mp[a2]--, mp[a3]--;
        }
        else
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