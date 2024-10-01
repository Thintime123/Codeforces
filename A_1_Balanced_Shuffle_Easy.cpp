#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

bool cmp(pii p1, pii p2)
{
    if (p1.second != p2.second)
        return p1.second < p2.second;
    else
        return p1.first > p2.first;
}
void solve()
{
    string s;
    cin >> s;
    vector<pii> arr(s.size() + 2); //  下标 -> 余额
    arr[0].first = 0, arr[0].second = 0;
    for (int i = 0; i < s.size(); i++)
    {
        arr[i + 1].first = i + 1;
        if (s[i] == '(')
            arr[i + 1].second = arr[i].second + 1;
        else
            arr[i + 1].second = arr[i].second - 1;
    }
    for(int i=0;i<=s.size();i++)
        cout<<arr[i].first<<' '<<arr[i].second<<endl;

    sort(all(arr), cmp);
    for (int i = 0; i < s.size(); i++)
        cout << s[arr[i].first];
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}