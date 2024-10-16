#include <bits/stdc++.h>

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n), brr(m);
    int *mp1 = new int[k + 1], *mp2 = new int[k + 1];
    fer(i, n) cin >> arr[i];
    fer(i, m) cin >> brr[i];
    sort(all(arr)), sort(all(brr));

    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            mp1[arr[i]] = 1;
        else
            break;

    for (int i = 0; i < m; i++)
        if (brr[i] <= k)
            mp2[brr[i]] = 1;
        else
            break;

    int cnt1 = k / 2, cnt2 = k / 2;
    bool *ok = new bool[k + 1]{};

    for (int i = 1; i <= k; i++)
    {
        if (mp1[i] == 0 && mp2[i] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    // 说明都有
    for (int i = 1; i <= k; i++)
    {
        if (mp1[i] == 0 && cnt2 > 0)
        {
            cnt2--;
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
        if (mp2[i] == 0 && cnt1 > 0)
        {
            cnt1--;
            continue;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
        if (!mp1[i] && !mp2[i])
        {
            if (cnt1 < cnt2)
                cnt2--;
            else
                cnt1--;
        }
        if (cnt1 < 0 || cnt2 < 0)
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