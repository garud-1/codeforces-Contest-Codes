 #include <bits/stdc++.h>
 using namespace std;
 
 // ----------------- Data types and other shortnames ------------------
 #define ll long long
 #define ld long double
 #define pb push_back
 #define umap unordered_map
 #define uset unordered_set
 #define all(a) (a).begin(), (a).end()
 #define print(a) for(auto i : a) cout << i << " ";
 #define py cout << "YES" << endl;
 #define pn cout << "NO" <<endl;
 
 #define debug(x) std::cerr << #x <<" "; _print(x); std::cerr << std::endl;
 void _print(ll t) {cerr << t;}
 void _print(int t) {cerr << t;}
 void _print(string t) {cerr << t;}
 void _print(char t) {cerr << t;}
 void _print(long double t) {cerr << t;}
 void _print(double t) {cerr << t;}
 void _print(unsigned long long t) {cerr << t;}
 
 template <class T, class V> void _print(pair <T, V> p);
 template <class T> void _print(vector <T> v);
 template <class T> void _print(set <T> v);
 template <class T, class V> void _print(map <T, V> v);
 template <class T> void _print(multiset <T> v);
 template <class T, class V> void _print(pair <T, V> p) {cerr << "{ "; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";}
 template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
 template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
 template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << ", ";} cerr << "]";}
 template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << ", ";} cerr << "]";}
 // ----------------- Loop -----------------------------------------------
 #define loop(s, e) for (ll ii = s; ii <= e; ii++)
 #define rloop(s, e) for (ll ii = s; ii >= e; ii--)
 #define input(arr, n) for(ll ii=0;ii<=n;ii++) cin >> arr[ii];
 
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
 C. Good Prefixes2 seconds256 megabytesstandard inputstandard output
Alex thinks some array is good if there exists some element that can be represented as the sum of all other elements (the sum of all other elements is 0
 if there are no other elements). For example, the array [1,6,3,2]
 is good since 1+3+2=6
. Furthermore, the array [0]
 is also good. However, the arrays [1,2,3,4]
 and [1]
 are not good.

Alex has an array a1,a2,…,an
. Help him count the number of good non-empty prefixes of the array a
. In other words, count the number of integers i
 (1≤i≤n
) such that the length i
 prefix (i.e. a1,a2,…,ai
) is good.

Input
The first line of the input contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
) — the number of elements in the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai≤109
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 
 */
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    int goodPrefixes = 0;

    for(int i = 0; i < n; i++){
        prefixSum += a[i];
        if(prefixSum == 0 || prefixSumCount[prefixSum] > 0){
            goodPrefixes++;
            prefixSumCount.clear();
            prefixSum = 0;
        }
        prefixSumCount[prefixSum]++;
    }

    cout << goodPrefixes << endl;
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