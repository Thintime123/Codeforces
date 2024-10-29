#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i > n; --i)

const int MOD = 1e9 + 7;
const int N = 1e5 + 2;

vector<int> p;

void prework(vector<int> &p)
{
    fer(i, 10, N)
    {
        int cur = i;
        bool f = true;
        while (cur)
        {
            if (cur % 10 > 1)
            {
                f = false;
                break;
            }
            cur /= 10;
        }
        if (f)
            p.push_back(i);
    }
}
void solve()
{
    int n;
    cin >> n;
    bool ok = false;

    if(n == 1){puts("YES");return;}
    fer(i, 0, p.size())
    {
        if (n % p[i] == 0)
        {
            n /= p[i];
            i --;
        }
        if (n == 1)
        {
            ok = true;
            break;
        }
    }
    if (ok)
        puts("YES");
    else
        puts("NO");
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    prework(p);
    while (T--)
    {
        solve();
    }

    return 0;
}