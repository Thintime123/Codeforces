#include <bits/stdc++.h>

using namespace std;

#define ll long long
// #define int ll
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define fer(i, m, n) for (int i = m; i < n; ++i)
#define ferd(i, m, n) for (int i = m; i >= n; --i)

const int MOD = 1e9 + 7;
const int N = 2e5 + 2;

signed main()
{
    int n;
    scanf("%d", &n);
    n++;
    bool *vis = new bool[n / 2 + 2]{};
    fer(i, 1, n){
        int a;
        scanf("%d", &a);
        if(vis[a % (n / 2)] == false) vis[a % (n / 2)] = true;
        else vis[a % (n / 2)] = false;
    }
    fer(i, 0, n / 2 + 2){
        if(vis[i]){
            printf("%d", i + 1);
            break;
        }
    }
    delete []vis;
    return 0;
}