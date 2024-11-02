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

char arr[310][310];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

string f(int x, int y){
    int d = 0;
    string s;
    for(int k=0;k<n*m;k++){
        s += arr[x][y];

        int a = x + dx[d], b = y + dy[d];
        if(a < 1 || a > n || b < 0 || b > m){
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
    return s;
}
void solve() {
    memset(arr, '0', sizeof arr);
    cin >> n >> m;
    string s;
    fer(i, 0, n){
        cin >> s;
        fer(j, 0, m){
            arr[i+1][j+1] = s[j];
        }
    }

    // fer(i, 1, n + 1){
    //     fer(j, 1, m + 1) cout << arr[i][j];
    //     cout << endl;
    // }
    int cnt1 = 0, cnt2 = 0;
    string s1 = f(1, 1);
    string s2 = f(1, m);
    fer(i, 0, s1.size() - 3){
        if(s1.substr(i, 4) == "1543"){
            cnt1++;
            i += 4;
        }
    }
    fer(i, 0, s2.size() - 3){
        if(s1.substr(i, 4) == "1543"){
            cnt2++;
            i += 4;
        }
    }
    cout << max(cnt1, cnt2) << '\n';
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