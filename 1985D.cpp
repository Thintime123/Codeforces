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
    int n, m;
    cin >> n >> m;
    vector<string>arr(n + 1);

    fer(i, 1, n + 1){
        cin >> arr[i];
    }
    int upx, upy, lex, ley, dox, doy, rix, riy;
    bool ok = false;
    fer(i, 1, n + 1){
        fer(j, 1, m + 1){
            if(arr[i][j] == '#'){
                upx = i, upy = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    ok = false;
    ferd(i, n, 1){
        fer(j, 1, m + 1){
            if(arr[i][j] == '#'){
                dox = i, doy = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    cout << upx << ' ' << upy << ' ' << dox << ' ' << doy << ' ';
    cout << upx + (dox - upx >> 1) << ' ' << upy << '\n';
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