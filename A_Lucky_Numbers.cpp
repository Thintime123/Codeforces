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
    int l, r;
    cin >> l >> r;
    int ans = 0;
    int mx = -1;
    for (int i = l; i <= r; i++)
    {
        string s = to_string(i);
        int a = *max_element(all(s)) - '0';
        int b = *min_element(all(s)) - '0';
        if (mx <= a - b)
        {
            mx = a - b;
            ans = i;
        }
        if(mx == 9) break;
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