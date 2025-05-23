#include<bits/stdc++.h>

using namespace std;

#define ll long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fer(i, n) for(int i = 0; i < n; ++i)
#define ferr(i, n) for(int i = 1; i <= n; ++i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int>arr(n);
    fer(i,n) cin >> arr[i];
    sort(all(arr));

    int ans = 0;
    int l = 0, r = m;
    while(l <= r){
        int mid = l + (r - l >> 1);
        auto check=[&](){
            int i = 0, j = 1;
            int s = arr[i];
            while(i < j && j < n){
                if(arr[j] - arr[i] <= 1) s += arr[j];
                
            }
        };
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}