#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.rdbuf(cout.rdbuf());
#define f(i,a,b) for (ll (i)=(a); (i)<(b); (i)++)
#define rf(i,a,b) for (ll (i)=(a); (i)>=(b); (i)--)
#define vll vector<ll>
#define vvll vector<vll>
#define in(n) ll n; cin>>n;
#define sin(s) string (s); cin>>(s);
#define vin(v,n) vll (v)(n); f(i,0,n)cin>>(v)[i];
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sort(v) sort(all(v));
#define rsort(v) sort(v) reverse(all(v));
#define pYES cout<<"YES\n";
#define pNO cout<<"NO\n";
const ll mod = 1000000007;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// Mod Template
template <typename T>
constexpr T power(T a, ll b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template <typename T>
constexpr T safeMod(T x, T m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

template <typename T>
constexpr std::pair<T, T> invGcd(T a, T b) {
    a = safeMod(a, b);
    if (a == 0) {
        return {b, 0};
    }

    T s = b, t = a;
    T m0 = 0, m1 = 1;

    while (t) {
        T u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }

    if (m0 < 0) {
        m0 += b / s;
    }

    return {s, m0};
}

template <typename T>
struct ModInt {
public:
    constexpr ModInt() : x(0) {}
    constexpr ModInt(T x_) : x(safeMod(x_, mod())) {}

    constexpr static T mod() {
        return static_cast<T>(mod_);
    }

    constexpr T val() const {
        return x;
    }

    constexpr ModInt operator-() const {
        return ModInt(x == 0 ? 0 : mod() - x);
    }

    constexpr ModInt pow(ll b) const { 
        ModInt res = 1;
        ModInt a = *this; 
        while (b > 0) {
            if (b & 1) {
                res *= a;
            }
            a *= a;
            b >>= 1;
        }
        return res;
    }

    constexpr ModInt inv() const {
        assert(x != 0);
        return pow(mod() - 2); 
    }

    constexpr ModInt &operator*=(const ModInt &rhs) & {
        x = (static_cast<long long>(x) * rhs.x) % mod();
        return *this;
    }

    constexpr ModInt &operator+=(const ModInt &rhs) & {
        x += rhs.x;
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }

    constexpr ModInt &operator-=(const ModInt &rhs) & {
        x -= rhs.x;
        if (x < 0) {
            x += mod();
        }
        return *this;
    }

    constexpr ModInt &operator/=(const ModInt &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr bool operator==(const ModInt &lhs, const ModInt &rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr std::istream &operator>>(std::istream &is, ModInt &a) {
        T i;
        is >> i;
        a = i;
        return is;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModInt &a) {
        return os << a.val();
    }

private:
    static constexpr T mod_ = 1000000007;
    T x;
};

using Z = ModInt<long long>;
// Mod template ends here

template <typename T>
void _print(T x) { cerr << x; }
template <typename T, typename V>
void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template <typename T>
void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <typename T>
void _print(set<T> s) { cerr << "{ "; for (T i : s) { _print(i); cerr << " "; } cerr << "}"; }
template <typename T, typename V>
void _print(map<T, V> m) { cerr << "{ "; for (auto i : m) { _print(i); cerr << " "; } cerr << "}"; }
/* *********************Template ends here************** */

void solve() {
    in(n); in(q);
    vin(a, n); vin(b, n);

    vll c = a, d = b;
    sort(c); sort(d);

    Z ans=1;
    f(i, 0, n) ans = ans * min(c[i], d[i]);

    cout << ans;

    f(i, 0, q) {
        in(o); in(x); x--;

        if (o == 1) {
            a[x]++;
            ll j = lower_bound(all(c), a[x]) - c.begin() - 1;
            ans /= min(c[j], d[j]); 
            c[j]++;
            ans = ans * min(c[j], d[j]);
        } else {
            b[x]++;
            ll j = lower_bound(all(d), b[x]) - d.begin() - 1;
            ans /= min(c[j], d[j]); 
            d[j]++;
            ans = ans * min(c[j], d[j]);
        }

        cout << " " << ans;
    }

    cout << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) solve();
}