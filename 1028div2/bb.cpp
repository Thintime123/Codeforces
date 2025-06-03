#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//#define int ll
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define fer(i, m, n) for(int i = m; i < n; ++i)
#define ferd(i, m, n) for(int i = m; i >= n; --i)
#define dbg(x) cout << #x << ' ' << char(61) << ' ' << x << '\n'

const int MOD = 998244353;
const int N = 2e5 + 2;
const int inf = 1e9;

struct Mint {
    using i64 = long long;
    static int mod;                       // 运行时模数
    int val;                              // 始终保持 0 ≤ val < mod

    /* ---------- 设置 / 读取模数 ---------- */
    static void set_mod(int m) { mod = m; }
    static int  get_mod()      { return mod; }

    /* ---------- 构造 ---------- */
    Mint(long long v = 0) {
        if (mod == 0) {
            cerr << "Error: Mint::mod 未初始化\n";
            exit(1);
        }
        val = int(v % mod);
        if (val < 0) val += mod;
    }

    /* ---------- 基本运算 ---------- */
    Mint& operator+=(const Mint& rhs) {
        val += rhs.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    Mint& operator-=(const Mint& rhs) {
        val -= rhs.val;
        if (val < 0) val += mod;
        return *this;
    }
    Mint& operator*=(const Mint& rhs) {
        val = int((1ULL * val * rhs.val) % mod);
        return *this;
    }
    Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }

    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend bool operator==(const Mint& a, const Mint& b){ return a.val == b.val; }
    friend bool operator!=(const Mint& a, const Mint& b){ return a.val != b.val; }

    /* ---------- 快速幂 ---------- */
    Mint pow(long long e) const {
        Mint base = *this, res = 1;
        while (e) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }

    /* ---------- 逆元（自动选择算法） ---------- */
    Mint inv() const {
        // 若 mod 是常见质数，直接费马求逆；否则走扩展欧几里得
        if (is_probable_prime(mod))
            return pow(mod - 2);          // Θ(log mod) 乘法取模
        else
            return Mint(inv_euclid(val, mod)); // Θ(log mod) 整除取余
    }

    /* ---------- 流输入输出（可选） ---------- */
    friend ostream& operator<<(ostream& os, const Mint& m){ return os << m.val; }
    friend istream& operator>>(istream& is, Mint& m){
        long long x; is >> x;
        m = Mint(x);
        return is;
    }

private:
    /* --- Miller–Rabin 准素性检测：常用整数足够 --- */
    static bool is_probable_prime(long long n) {
        if (n < 2) return false;
        for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n % p == 0) return n == p;
        }
        auto modmul = [&](long long a, long long b) -> long long {
            return (__int128)a * b % n;
        };
        auto modpow = [&](long long a, long long d) -> long long {
            long long r = 1;
            while (d) {
                if (d & 1) r = modmul(r, a);
                a = modmul(a, a);
                d >>= 1;
            }
            return r;
        };
        long long d = n - 1, s = 0;
        while ((d & 1) == 0) d >>= 1, ++s;
        for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if (a % n == 0) continue;
            long long x = modpow(a, d);
            if (x == 1 || x == n - 1) continue;
            bool comp = true;
            for (int r = 1; r < s; ++r) {
                x = modmul(x, x);
                if (x == n - 1) { comp = false; break; }
            }
            if (comp) return false;
        }
        return true;
    }

    /* --- 扩展欧几里得求 inv(x) (mod m) --- */
    static long long inv_euclid(long long a, long long m) {
        long long x = 0, last_x = 1;
        while (m) {
            long long q = a / m;
            tie(a, m) = pair(m, a - q * m);
            tie(last_x, x) = pair(x, last_x - q * x);
        }
        if (a != 1) {
            cerr << "Error: gcd(val, mod) ≠ 1, 无逆元\n";
            exit(1);
        }
        if (last_x < 0) last_x += Mint::mod;
        return last_x;
    }
};

int Mint::mod = 998244353;
using mint = Mint;

mint arr[N];

void init() {
    arr[0] = 1, arr[1] = 2;
    fer(i, 2, N) {
        arr[i] = arr[i - 1] * 2;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1);
    vector<pii> prep(n + 1), preq(n + 1);

    fer(i, 1, n + 1) cin >> p[i];
    fer(i, 1, n + 1) cin >> q[i];

    fer(i, 1, n + 1) {
        if(prep[i - 1].first <= p[i]) {
            prep[i] = {p[i], i};
        } else {
            prep[i] = prep[i - 1];
        }
        if(preq[i - 1].first <= q[i]) {
            preq[i] = {q[i], i};
        } else {
            preq[i] = preq[i - 1];
        }
    }

    fer(i, 1, n + 1) {
        pii p1 = {prep[i].first, q[i - prep[i].second + 1]};
        pii p2 = {preq[i].first, p[i - preq[i].second + 1]};
        if(p1 < p2) p1 = p2;
        mint x = arr[p1.first] + arr[p1.second];
        cout << x << ' ';
    }
    cout << '\n';    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    init();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}