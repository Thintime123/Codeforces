#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, m, n) for(int i = m; i < n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    vector<int>ind; // 存每个未被匹配的左括号的下标
    fer(i, 0, n){
        if(s[i] == '_'){
            if(ind.empty()) s[i] = '(';
            else s[i] = ')';
        }
        if(s[i] == '(') ind.push_back(i);
        else{
            ans += i - ind.back();
            ind.pop_back();
        }
    }
    cout << ans << '\n';
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