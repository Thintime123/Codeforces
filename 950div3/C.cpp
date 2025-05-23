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
    vector<int> arr(n), brr(n);
    fer(i, 0, n) cin >> arr[i];
    fer(i, 0, n) cin >> brr[i];

    int m;
    cin >> m;
    vector<int> d(m);

    fer(i, 0, m) cin >> d[i];
    map<int, int>mp; // 需要的数量

    bool ok = true;
    fer(i, 0, n)
    	if(arr[i] != brr[i]) mp[brr[i]]++, ok = false;

    if(ok){
        if(find(all(arr), d.back()) != arr.end()){cout << "YES" << '\n'; return;}
        else {cout << "NO" << '\n'; return;}
    }
    else{
        if(find(all(brr), d.back()) == brr.end()){cout << "NO" << '\n'; return;}
        map<int, int>dmap;
        for(auto c:d) dmap[c]++;

        for(auto [num, cnt]:mp){
            if(dmap[num] < cnt){cout << "NO" << '\n'; return;}
        }
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