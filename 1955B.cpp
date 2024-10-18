#include <bits/stdc++.h>
#include <unordered_map>

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
    int *arr = new int[n];
    for (int i = 1; i < n; i++)
    {
        if (mp[arr[0] + i * d])
        {
            arr[i] = arr[0] + i * d;
            mp[arr[i]]--;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[arr[j] + c])
            {
                arr[j] += c;
                mp[arr[j]]--;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
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