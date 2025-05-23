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
    string s;
    cin >> s;

    int n = s.size();
    vector<bool> vis(n, false);

    stack<int>sk1, sk2;

    fer(i, 0, n){
        if(s[i] >= 'a' && s[i] <= 'z' && s[i] != 'b') sk1.push(i);
        else if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'B') sk2.push(i);

        if(s[i] == 'b'){
            vis[i] = true;
            if(!sk1.empty()) vis[sk1.top()] = true, sk1.pop();
        }
        else if(s[i] == 'B'){
            vis[i] = true;
            if(!sk2.empty()) vis[sk2.top()] = true, sk2.pop();
        }
    }
    fer(i, 0, n){
        if(!vis[i]) cout << s[i];
    }
    cout << '\n';
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