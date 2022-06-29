// This code made by Muhammad Gilang Ramadhan

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define lb                  lower_bound
#define ub                  upper_bound
#define setbits(x)          __builtin_popcountll(x)
#define trailing_zeros(x)   __builtin_ctzll(x)
#define leading_zeros(x)    __builtin_clzll(x)
#define sz(v)               (int)v.size()
#define ps(y)               cout << fixed << setprecision(y)
#define ms(arr, v)          memset(arr, v, sizeof(arr))
#define all(v)              v.begin(), v.end()
#define rall(v)             v.rbegin(), v.rend()
#define trav(x, v)          for(auto &x: v)
#define w(t)                int t; cin >> t; while(t--)
#define rep(i, a, b)        for(int i = a; i <= b; i++)
#define rrep(i, a, b)       for(int i = a; i >= b; i--)
#define rep0(i, n)          rep(i, 0, n - 1)
#define rrep0(i, n)         rrep(i, n - 1, 0)
#define rep1(i, n)          rep(i, 1, n)
#define rrep1(i, n)         rrep(i, n, 1)
#define inp(arr, n)         rep0(i, n) cin >> arr[i];
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mii;
typedef map<char, ll> mci;
typedef set<string> ss;
typedef set<int> si;
typedef set<ll> sl;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vi, greater<>> pq_mn;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;

/*
 * find_by_order(i) -> returns an iterator to the element at ith position (0 based)
 * order_of_key(i)  -> returns the position of element i (0 based)
 */
 
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll inf = 2e18;
const ld eps = 1e-10, pi = acos(-1.0);
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int CariIndexPertama(int& temp, int n)
{
 
    if (n == 1)
        return 0;
    n--;
 
    int IndexPertama, n_partial_fact = n;
 
    while (temp >= n_partial_fact
           && n > 1) {
        n_partial_fact
            = n_partial_fact
              * (n - 1);
        n--;
    }
 
    IndexPertama = temp / n_partial_fact;
 
    temp %= n_partial_fact;
 
    return IndexPertama;
}

// Logic to find kth at permutation of n first number 
string Find(int n, int k)
{
    string ans = "";
 
    si s;
 
    rep(i,1,n){
        s.insert(i);
    }
 
    si::iterator itr;
    
    itr = s.begin();
 
    k = k - 1;
 
    rep(i,0,n-1) {
 
        int index = CariIndexPertama(k, n - i);
 
        advance(itr, index);

        ans += (to_string(*itr));
 
        s.erase(itr);
 
        itr = s.begin();
    }
    return ans;
}

void solve(){
    int Q; cin >> Q;
    while(Q--){
        int N, M; cin >> N >> M;
        cout << Find(N,M) << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    solve();
 
    return 0;
}