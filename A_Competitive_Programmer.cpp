#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    string n;
    cin >> n;

    bool f3 = false, f4 = false, f5 = false;
    int s = 0;
    for (char c : n)
        s += (c - '0');

    f3 = (s % 3 == 0);
    if (!f3)
    {
        cout << "cyan\n";
        return;
    }
    for (char c : n)
    {
        if (c - '0' == 0)
        {
            f5 = true;
            break;
        }
    }
    if (!f5)
    {
        cout << "cyan\n";
        return;
    }
    int cnt = 0;
    for (char c : n)
    {
        if ((c - '0') % 2 == 0)
        {
            cnt++;
            if (cnt == 2)
                break;
        }
    }
    f4 = cnt == 2;
    if (!f4)
    {
        cout << "cyan\n";
        return;
    }
    cout << "red\n";
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