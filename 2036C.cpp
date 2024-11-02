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

int cnt;

void prework(string s, map<int, int> &mp)
{
    fer(i, 0, s.size() - 4)
    {
        if (s.substr(i, 4) == "1100")
        {
            cnt++;
            mp[i]++;
            mp[i + 1]++;
            mp[i + 2]++;
            mp[i + 3]++;
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;

    map<int, int> mp;
    prework(s, mp);

    while (q--)
    {
        int i, v;
        cin >> i >> v;
        i--;

        if (s[i] != char(v + '0'))
        {
            s[i] = char(v + '0');
            // int l = max(0, i - 3), r = min((int)(s.size() - 4), i);
            // f1 = false;
            // for(int j = l; j <= r; j ++){
            //     if(s.substr(j, 4) == "1100"){
            //         f1 = true;
            //         break;
            //     }
            // }

            if (mp[i])
            {
                // 本来有
                int l = max(0, i - 3), r = min((int)(s.size() - 1), i + 3);
                fer(k, l, r + 1){
                    if(mp[i]) mp[i]--;
                }
                cnt -= 2;
            }
            else
            {
                // 本来没有
                int l = max(0, i - 3), r = min((int)(s.size() - 1), i + 3);
                if(r - l + 1 >= 4){
                    fer(k, l, r - 2){
                        if(s.substr(k,4)=="1100"){
                            mp[k]++;
                            mp[k+1]++;
                            mp[k+2]++;
                            mp[k+3]++;
                            cnt++;
                        }
                    }
                }
            }
        }
        if(cnt > 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}