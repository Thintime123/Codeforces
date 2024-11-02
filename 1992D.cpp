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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = " " + s;

    bool f = true;
    int cnt = k;
    
    fer(i, 0, n + 1){
        if(i == n){
            if(s[i] == 'L'){
                if(m > 0) break;
                else{f = false; break;}
            }
            
        }
        fer(j, i + 1, n + 1){
            if(s[j] == 'L'){
                if(j - i <= m){
                    i = j - 1;
                    break;
                }
                else{
                    string ss = s.substr(i + 1, j - i);
                    for(char c : ss){
                        if(c == 'C'){cout << "NO\n"; return;}
                        if(c == 'W') cnt--;
                        if(cnt < 0){cout << "NO\n"; return;}
                    }
                    i = j - 1;
                    break;
                }
            }
            // s[j] != 'L'
            if(j == n){
                if(j - i + 1 <= m){cout << "YES" << '\n'; return;}
                else{
                    string ss = s.substr(i + 1, j - i);
                    for(char c : ss){
                        if(c == 'C'){cout << "NO\n"; return;}
                        if(c == 'W') cnt--;
                        if(cnt < 0) {cout << "NO\n"; return;}
                    }
                }
            }
        }
    }
    if(f) puts("YES");
    else puts("NO");
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