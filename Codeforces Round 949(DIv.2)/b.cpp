#include <bits/stdc++.h>
using namespace std;

// ----------------- Data types and other shortnames ------------------
#define ll long long
#define ld long double
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define all(a) (a).begin(), (a).end()
#define print(a)     \
    for (auto i : a) \
        cout << i << " ";
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;

#define debug(x)            \
    std::cerr << #x << " "; \
    _print(x);              \
    std::cerr << std::endl;
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{ ";
    _print(p.ff);
    cerr << ", ";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
// ----------------- Loop -----------------------------------------------
#define loop(s, e) for (ll ii = s; ii <= e; ii++)
#define rloop(s, e) for (ll ii = s; ii >= e; ii--)
#define input(arr, n)              \
    for (ll ii = 0; ii <= n; ii++) \
        cin >> arr[ii];

// ----------------- Constant -------------------------------------------
const ll MOD = 1e9 + 7;
const double PI = 3.14;

// ----------------- storing (x,y) coordinate of point ------------------
template <typename T>
struct Point
{
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
};

// ------------------ Number theory ----------------------------------------
ll fastpower(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}

ll sqrt(ld a)
{
    return sqrtl(a);
}

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

vector<ll> seive(ll N)
{
    vector<ll> primes(N + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= N; ++i)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;
        }
    }
    vector<ll> res;
    for (int i = 2; i <= N; ++i)
    {
        if (primes[i])
            res.push_back(i);
    }
    return res;
}

vector<vector<ll>> findDivisors(ll N)
{
    vector<vector<ll>> divisors(N);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

vector<ll> findPrimeDivisors(ll N)
{
    vector<ll> res;
    vector<ll> primes(N + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= N; ++i)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (primes[i] && N % i == 0)
        {
            res.push_back(i);
            while (N % i == 0)
                N /= i;
        }
        if (N == 1)
            break;
    }
    if (N != 1)
        res.push_back(N);
    return res;
}

// ------------------ Bit Manupation -----------------------------------
bool check_bit(ll a, ll i)
{
    if ((a & (1 << i)) != 0)
        return true;
    return false;
}

ll set_bit(ll a, ll i)
{
    return (a | (1 << i));
}

ll unset_bit(ll a, ll i)
{
    return (a & (~(1 << i)));
}

ll toggle_bit(ll a, ll i)
{
    return (a ^ (1 << i));
}

ll least_set_bit(ll a)
{
    return (a & (-a));
}

ll get_bit(ll a, ll i)
{
    return ((a >> i) & 1);
}

ll count_setBits(ll a)
{
    ll ans = 0;
    while (a)
    {
        a = a & (a - 1);
        ans++;
    }
    return ans;
}

/*

standard output
There is a sequence a0,a1,a2,…
 of infinite length. Initially ai=i
 for every non-negative integer i
.

After every second, each element of the sequence will simultaneously change. ai
 will change to ai−1∣ai∣ai+1
 for every positive integer i
. a0
 will change to a0∣a1
. Here, |
 denotes bitwise OR.

Turtle is asked to find the value of an
 after m
 seconds. In particular, if m=0
, then he needs to find the initial value of an
. He is tired of calculating so many values, so please help him!

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n,m
 (0≤n,m≤109
).

Output
For each test case, output a single integer — the value of an
 after m
 seconds.

*/

void solve()
{
    ll n, m;
    cin >> n >> m;
    // at first calculating the nth element first position
 
    // after one second the value of nth element is (n-1)|n|(n+1)

    if (m == 0)
    {
        cout << n << endl;
        return;
    }
    ll ans = 0;
    
    // after m turns the value of nth element is or of (n-i) where i is ranging from -m to m
    // so the value of nth element is or of (n-m) to (n+m)
    // taking only those terms in which we can take a valid value
    for (ll i = -m; i <= m; i++)
    {   if(n+i>=0)
        ans |= (n + i);
        else continue;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}