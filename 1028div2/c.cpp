#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        
        int g = a[0];
        for(int i = 1; i < n; i++) g = __gcd(g, a[i]);

        bool allEq = true;
        for(int x : a) if(x != g){ allEq = false; break; }
        if(allEq){
            cout << 0 << "\n";
            continue;
        }

        int cnt = 0;
        for(int x : a) if(x == g) cnt++;
        if(cnt > 0){
            cout << (n - cnt) << "\n";
            continue;
        }

        const int INF = 1e9;
        int MAXV = *max_element(a.begin(), a.end());
        vector<int> dist(MAXV + 1, INF);
        deque<int> dq;
        for(int x : a){
            if(dist[x] > 0){
                dist[x] = 0;
                dq.push_back(x);
            }
        }
        while(!dq.empty()){
            int u = dq.front(); dq.pop_front();
            int du = dist[u];
            if(u == g) break;
            for(int x : a){
                int w = __gcd(u, x);
                if(du + 1 < dist[w]){
                    dist[w] = du + 1;
                    dq.push_back(w);
                }
            }
        }
        int dist_g = dist[g];
        cout << (dist_g + (n - 1)) << "\n";
    }
    return 0;
}