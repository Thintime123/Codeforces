#include<bits/stdc++.h>

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

    vector<int>arr(n + 1);
    fer(i, 1, n + 1) cin >> arr[i];

    int s1 = arr[1], s2 = arr.back();
    int cnt = 0;

    int l = 1, r = n;
    while(l < r){
    	while(l < r - 1 && s1 < s2) l++, s1 += arr[l];
    	while(l < r - 1 && s1 > s2) r--, s2 += arr[r];
    	if(s1 == s2) cnt = l + (n - r + 1);
    	l++, s1 += arr[l];
    }
    cout << cnt << '\n';
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