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

class qNode {
public:
    int x, y, dist;
    qNode(int x, int y, int dist)
    {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};
 
// Variables Global
int dirx[4] = { 0, 1, 0, -1 };
int diry[4] = { 1, 0, -1, 0 };

int sizeArr, sizeAnsubArr;

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= sizeArr || y >= sizeAnsubArr)
        return false;
    return true;
}

bool isBorder(int i, int j, vector<vector<ll> >& arr)
{
    rep(idx,0,3){
        int x = i + dirx[idx];
        int y = j + diry[idx];
        if (isValid(x, y) && arr[x][y] == 0)
            return true;
    }
    return false;
}

void dfs(int i, int j, vector<vector<bool> >& visited,queue<qNode>& q, vector<vector<ll> >& arr)
{
    visited[i][j] = true;
    if (isBorder(i, j, arr)) {
        q.push(qNode(i, j, 0));
    }

    rep(idx,0,3){
        int x = i + dirx[idx];
        int y = j + diry[idx];
        if (isValid(x, y) && arr[x][y] == 1
            && !visited[x][y])
            dfs(x, y, visited, q, arr);
    }
}

int bfs(queue<qNode>& q, vector<vector<bool> >& visited,vector<vector<ll> >& arr)
{
    while (q.size() > 0) {
        qNode p = q.front();
        q.pop();
        rep(idx,0,3){
            int x = p.x + dirx[idx];
            int y = p.y + diry[idx];

            if (isValid(x, y) && arr[x][y] == 1
                && !visited[x][y]) {
                return p.dist;
            }
 
            if (isValid(x, y) && arr[x][y] == 0
                && !visited[x][y]) {
                q.push(qNode(x, y, 1 + p.dist));
                visited[x][y] = true;
            }
        }
    }
    return -1;
}

void solve(){
    int N; cin >> N;
    vvi arr;
    rep(i,0,N-1){
        vi temp;
        rep(j,0,N-1){
            ll A; cin >> A;
            temp.pb(A);
        }
        arr.pb(temp);
    }

    sizeArr = arr.size();
    sizeAnsubArr = arr[0].size();
    queue<qNode> q;
    vector<vector<bool> > visited(sizeArr,vector<bool>(sizeAnsubArr, false));
    bool found = false;
    rep(i,0,sizeArr-1){
        rep(j,0,sizeAnsubArr-1){
            if (arr[i][j] == 1) {
                dfs(i, j, visited, q, arr);
                found = true;
                break;
            }
        }
        if (found){
            break;
        }
    }
    cout << bfs(q, visited, arr) << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    solve();
 
    return 0;
}