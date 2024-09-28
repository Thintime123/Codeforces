#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

map<int, int> mp;

void get_ne(string s, int ne[])
{
    int m = s.size();
    ne[0] = -1;
    mp[-1]++;
    if (m == 1)
        return;
    ne[1] = 0;
    mp[0]++;
    int i = 2, cn = 0;
    while (i <= m)
    {
        while (cn > 0 && s[i - 1] != s[cn])
            cn = ne[cn];
        if (s[i - 1] == s[cn])
            ne[i] = ++cn;
        else
            ne[i] = 0;
        mp[ne[i++]]++;
    }
    return;
}
void solve()
{
    string s;
    cin >> s;
    int *ne = new int[s.size() + 2];
    get_ne(s, ne);
    string ss;
    int len = ne[s.size()];

    // for (int i = 0; i <= s.size(); i++)
    //     cout << ne[i] << ' ';
    // cout << endl;
    bool f = true;
    while (len > 0)
    {
        if (f && mp[len] > 1)
        {
            ss = s.substr(0, len);
            break;
        }
        else if (!f && mp[len] >= 1)
        {
            ss = s.substr(0, len);
            break;
        }
        f = false;
        len = ne[len];
    }
    cout << (len > 0 ? ss : "Just a legend");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}