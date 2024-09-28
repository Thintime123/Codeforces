#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> arr(3);
    for (int &c : arr)
        cin >> c;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';

    return 0;
}