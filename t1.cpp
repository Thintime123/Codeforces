#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fer(i, m, n) for(int i = m; i < n; ++i)

template <typename T>
inline T read()
{
    T x = 0;
    int y = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = read<ll>();
    ll s = n * (n + 1) / 2;
    fer(i, 1, n){
        int a = read<int>();s -= a;
    }
    write(s);return 0;
}