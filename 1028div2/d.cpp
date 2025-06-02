#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<ll> b(n+1);
        for(int i = 1; i <= n; i++) cin >> b[i];

        vector<array<int,3>> ops(q);
        vector<bool> hasTarget(n+1,false);
        for(int i = 0; i < q; i++){
            int x,y,z;
            cin >> x >> y >> z;
            ops[i]={x,y,z};
            hasTarget[z]=true;
        }
        
        vector<bool> seen(n+1,false);
        vector<ll> req(n+1, 0);
        
        for(int i = q-1; i >= 0; --i){
            int x = ops[i][0], y = ops[i][1], z = ops[i][2];
            if(seen[z]) continue;
            seen[z] = true;          
            
            req[x] = max(req[x], b[z]);
            req[y] = max(req[y], b[z]);
        }

        vector<ll> a(n+1, 0);
        bool bad = false;
        for(int i = 1; i <= n; i++){
            if(!hasTarget[i]){
                
                if(req[i] > b[i]){
                    bad = true;
                    break;
                }
                a[i] = b[i];
            } else {
                a[i] = req[i];
            }
        }
        if(bad){
            cout << "-1\n";
            continue;
        }
        
        vector<ll> c = a;
        for(auto &op: ops){
            int x=op[0], y=op[1], z=op[2];
            ll v = min(c[x], c[y]);
            c[z] = v;
            
            if(v != b[z]){
                bad = true;
                break;
            }
        }
        if(bad){
            cout << "-1\n";
        } else {
            for(int i = 1; i <= n; i++){
                cout << a[i] << (i==n?'\n':' ');
            }
        }
    }
    return 0;
}