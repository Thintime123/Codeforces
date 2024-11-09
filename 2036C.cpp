#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int cnt = 0;

    fer(i, 0, s.size() - 3){
        if(s.substr(i, 4) == "1100") cnt++;
    }
    while(q--){
        int ind, v;
        cin >> ind >> v;
        ind--;

        int cnt1 = 0, cnt2 = 0;
        // 改变前
        fer(i, max(0, ind - 3), min((int)s.size() - 3, ind + 1)){
            if(s.substr(i, 4) == "1100") cnt1++;
        }
        // 改变后
        s[ind] = char(v + '0');
        fer(i, max(0, ind - 3), min((int)s.size() - 3, ind + 1)){
            if(s.substr(i, 4) == "1100") cnt2++;
        }
        cnt += cnt2 - cnt1;
        if(cnt >= 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto start_time = clock();

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

#ifdef LOCAL
    cout << "\nTime : ";
    cout << (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000 << "ms\n";
#endif
    return 0;
}