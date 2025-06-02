#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << '=' << ' ' << x << '\n'


const int MAX_EXP = 100000;
const int MOD = 998244353;
vector<ll> init2(MAX_EXP+1);

void preinit() {
    init2[0] = 1;
    for (int i = 1; i <= MAX_EXP; i++) {
        init2[i] = (init2[i-1] * 2) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<int> prep(n);
    vector<int> preq(n);
    prep[0] = p[0];
    preq[0] = q[0];
    for (int i = 1; i < n; i++) {
        prep[i] = max(prep[i-1], p[i]);
        preq[i] = max(preq[i-1], q[i]);
    }

    vector<int> pos_p(n, -1);
    vector<int> pos_q(n, -1);
    for (int i = 0; i < n; i++) {
        pos_p[p[i]] = i;
        pos_q[q[i]] = i;
    }

    vector<ll> r(n);
    for (int s = 0; s < n; s++) {
        int M = max(prep[s], preq[s]);
        int can1 = -1;
        int can2 = -1;

        if (M == prep[s]) {
            int j0 = pos_p[M];
            if (j0 <= s) {
                int k0 = s - j0;
                can1 = q[k0];
            }
        }

        if (M == preq[s]) {
            int k0 = pos_q[M];
            if (k0 <= s) {
                int j0 = s - k0;
                can2 = p[j0];
            }
        }

        int d_val;
        if (can1 == -1 && can2 == -1) {
            d_val = 0;
        } else if (can1 == -1) {
            d_val = can2;
        } else if (can2 == -1) {
            d_val = can1;
        } else {
            d_val = max(can1, can2);
        }

        r[s] = (init2[M] + init2[d_val]) % MOD;
    }

    for (int i = 0; i < n; i++) {
        cout << r[i];
        if (i < n-1) 
            cout << ' ';
        else
            cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    preinit();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}