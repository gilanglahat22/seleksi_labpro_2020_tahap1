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
#define repS(i,a,b)         for(int i = a; i * i <= b; i++) 

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
 
bitset<1299709> Primes;

ll x4[] = {0,0,1,-1};
ll y4[] = {1,-1,0,0};
 
void BuildTree(vector<pair<ll,ll> > & tree, vector<ll> & ara, ll b, ll e, ll node)
{
    if(b == e){
        tree[node].first = ara[b];
        tree[node].second = 0;
        return;
    }
    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;
    BuildTree(tree,ara,b,mid,left);
    BuildTree(tree,ara,mid+1,e,right);
 
    tree[node].first = tree[left].first + tree[right].first;
}
 
ll query(vector<pair<ll,ll> > & ara, ll b, ll e, ll node, ll i, ll carry)
{
    if(b > i or e < i){
        return 0LL;
    }
    if(b >= i and e <= i){
        return ara[node].first+(carry*(e-b+1));
    }
    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;
 
    ll x = query(ara,b,mid,left,i,carry+ara[node].second);
    ll y = query(ara,mid+1,e,right,i,carry+ara[node].second);
 
    return (x+y);
}
 
void update(vector<pair<ll,ll> > & ara, ll b, ll e, ll node, ll i, ll j, ll  u)
{
    if(b > j or e < i){
        return;
    }
    if(b >= i and e <= j){
        ara[node].first+=((e-b+1)*u);
        ara[node].second+=u;
        return;
    }
    ll left = node << 1;
    ll right = left+1;
    ll mid = (b+e) >> 1;
 
    update(ara,b,mid,left,i,j,u);
    update(ara,mid+1,e,right,i,j,u);
 
    ara[node].first = ara[left].first+ara[right].first + ara[node].second*(e-b+1);
}

void solve(){
    // // Generates 10^5 prime numbers
    ll AllPrimes[100000];
    Primes[0] = 1;
    for (int i = 3; i*i <= 1299709; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= 1299709; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
    long long index = 0;
    for (int i = 1; i <= 1299709; i++) {
        if (i == 2){
            AllPrimes[index] = i;
            index++;
        }
        else if (i % 2 == 1 && Primes[i / 2] == 0){
            AllPrimes[index] = i;
            index++;
        }
    }
    ll N,Q;
    cin >> N >> Q;
    vector<ll> ara(N+1);
    vector<pair<ll,ll> > tree(4*N);
    rep(i,1,N){
        cin >> ara[i];
    }
    BuildTree(tree,ara,1,N,1);
    ll tipe,A,B,X;
    while(Q--){
        cin >> tipe;
        if(tipe == 1){
            cin >> A;
            cout << query(tree,1,N,1,A,0LL) << "\n";
        }else{
            cin >> A >> B >> X;
            update(tree,1,N,1,A,B,AllPrimes[X-1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
	return 0;
}