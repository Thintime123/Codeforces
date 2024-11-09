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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool finds(string s){
    fer(i, 0, s.size() - 3){
        if(s.substr(i, 4) == "1543")
            return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>>arr(n, vector<int>(m));
    fer(i, 0, n){
        string s;
        cin >> s;
        fer(j, 0, s.size())
            arr[i][j] = (int)(s[j] - '0');
    }
    int c = 0;
    while(n){
        string s;
        int x = c, y = c, d = 0;
        fer(i, 0, 2 * (n + m - 2)){
            s += to_string(arr[x][y]);
            int a = x + dx[d], b = y + dy[d];
            if(a < 0 || a >= n || b < 0 || b >= m){
                d = (d + 1) % 4;
                x += dx[d], y += dy[d];
            }
        }
        n -= 2, m -= 2;
        c ++;
        string s1 = s.substr(1) + s[0];
        string s2 = s1.substr(1) + s1[0];
        string s3 = s2.substr(1) + s2[0];
        if(finds(s) || finds(s1) || finds(s2) || finds(s3))
            cout << "YES" << endl;
        else cout << "NO" << endl;
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