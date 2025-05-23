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
    int n;
    cin >> n;
    vector<int> arr(n);
    int c1 = 1, c2 = 1;
    for (int &c : arr)
        cin >> c;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1])
            c1++;
        else
            break;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] == arr[i - 1])
            c2++;
        else
            break;
    }
    if (arr.front() == arr.back())
        cout << max(0LL, n - c1 - c2) << endl;
    else
        cout << n - max(c1, c2) << endl;
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