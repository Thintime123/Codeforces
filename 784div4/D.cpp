#include<bits/stdc++.h>
#include <vector>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define inf INT_MAX

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = "W" + s + "W";
    vector<int>arr;
    fer(i, 0, s.size())
        if(s[i] == 'W') arr.push_back(i);

    fer(i, 0, arr.size() - 1){
        int l = arr[i], r = arr[i + 1];
        int c1 = 0, c2 = 0;

        fer(j, l + 1, r){
            if(s[j] == 'R') c1++;
            else if(s[j] == 'B') c2++;
        }
        //cout << c1 << ' ' << c2 << '\n';
        if(c1 * c2 == 0 && !(c1 + c2 == 0)){cout << "NO" << '\n'; return;}
    }
    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}