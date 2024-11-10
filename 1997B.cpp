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
    int n;
    cin >> n;
    vector<string>arr(2);
    fer(i, 0, 2) cin >> arr[i];
    int ans = 0;

    fer(i, 0, 2){
        fer(j, 1, n - 1){
            if(i == 0){
                if(arr[i][j] == '.' && arr[i][j - 1] == 'x' && arr[i][j + 1] == 'x' && arr[i + 1][j - 1] == '.' && arr[i + 1][j] == '.' && arr[i + 1][j + 1] == '.')
                    ans++;
            }
            else{
                if(arr[i][j] == '.' && arr[i][j - 1] == 'x' && arr[i][j + 1] == 'x' && arr[i - 1][j - 1] == '.' && arr[i - 1][j] == '.' && arr[i - 1][j + 1] == '.')
                    ans++;
            }
        }   
    }
    cout << ans << '\n';
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