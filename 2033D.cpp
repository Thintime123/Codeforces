#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> s(n + 1);

    fer(i, 1, n + 1)
    {
        cin >> arr[i];
        s[i] = s[i - 1] + arr[i];
    }

    // fer(i, 1, n + 1) cout << s[i] << ' ';
    // cout << endl;

    int ans = 0;
    set<int> st;
    st.insert(0);
    fer(i, 1, n + 1)
    {
        if (st.count(s[i]))
        {
            ans++;
            st.clear();
            st.insert(s[i]);
        }
        else
            st.insert(s[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}