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
#define hapusUnique(n)      n.erase(unique(all(n)),n.end());
#define lower(a,b,c)        lower_bound(all(a),b[c]) - a.begin();

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
typedef vector<pair<pair<ll,ll>,pair<ll,ll>>> tmpl;

/*
 * find_by_order(i) -> returns an iterator to the element at ith position (0 based)
 * order_of_key(i)  -> returns the position of element i (0 based)
 */

const int MAXN = 100000;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll inf = 2e18;
const ld eps = 1e-10, pi = acos(-1.0);
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll arahX[MAXN], arahY[MAXN], sizeMasingTemp[MAXN], u[2*MAXN], B[MAXN];

ll multiply(ll A, ll B){
    return A*B;
}

bool isBerlawananArah(ll x1, ll x2){
    if(multiply(x1,x2) == -1){
        return true;
    }
    return false;
}

ll Query(ll lower, ll upper){
    ll temp = 0;
    upper += 5;
    while(upper){
        temp += u[upper];
        upper -= upper & (-upper);
    }
    lower += 4;
    while(lower){
        temp -= u[lower];
        lower -= lower & (-lower);
    }
    return temp;
}

void Ubah(ll A, ll B){
    A += 5;
    while(A < 2 * MAXN){
        u[A] += B;
        A += A & (-A);
    }
}

void solve(){
    tmpl tampungGaris;
    vi jarakHorizontal,jarakVertical;
    vvi temp;
    ll N; cin >> N;
    ll sum = 0;
    ll prevX = 0,prevY = 0;
    rep(i,0,N-1){
        char A;
        cin >> A >> B[i];
        if(A == 'N'){
            arahY[i]++;
        }else if(A == 'S'){
            arahY[i]--;
        }else if(A == 'E'){
            arahX[i]++;
        }else if(A == 'W'){
            arahX[i]--;
        }
        if(i && ((isBerlawananArah(arahX[i], arahX[i-1])) || (isBerlawananArah(arahY[i], arahY[i-1])))){
            N = i;
            break;
        }
        sum += B[i];
        ll curX = prevX + arahX[i] * (B[i] - 1);
        ll curY = prevY + arahY[i] * (B[i] - 1);
        tampungGaris.pb(mp(mp(min(prevX,curX),min(prevY,curY)),mp(max(prevX,curX),max(prevY,curY))));
        jarakHorizontal.pb(tampungGaris[tampungGaris.size()-1].first.first);
        jarakHorizontal.pb(tampungGaris[tampungGaris.size()-1].second.first);
        jarakVertical.pb(tampungGaris[tampungGaris.size()-1].first.second);
        jarakVertical.pb(tampungGaris[tampungGaris.size()-1].second.second);
        if(!arahY[i]){
            temp.pb({tampungGaris[tampungGaris.size()-1].second.first,1,tampungGaris[tampungGaris.size()-1].first.second});
            temp.pb({tampungGaris[tampungGaris.size()-1].first.first,-1,tampungGaris[tampungGaris.size()-1].first.second});
        }
        else{
            temp.pb({tampungGaris[tampungGaris.size()-1].first.first,0,tampungGaris[tampungGaris.size()-1].first.second,tampungGaris[tampungGaris.size()-1].second.second});
        }
        prevX = curX + arahX[i];
        prevY = curY + arahY[i];
        sizeMasingTemp[i+1] = temp.size();
    }
    sort(all(jarakHorizontal));
    sort(all(jarakVertical));
    hapusUnique(jarakHorizontal);
    hapusUnique(jarakVertical);
    trav(i,temp){
        if(i.size() != 3){
            i[0] = lower(jarakHorizontal,i,0);
            i[2] = lower(jarakVertical,i,2);
            i[3] = lower(jarakVertical,i,3);
        }else{
            i[0] = lower(jarakHorizontal,i,0);
            i[2] = lower(jarakVertical,i,2);
        }
    }
    ll lower = 0, Upper = N + 1;
    while(Upper - lower >= 2){
        ll tengah = (lower + Upper)/2;
        vvi NewTemp(temp.begin(),temp.begin()+sizeMasingTemp[tengah]);
        sort(all(NewTemp));
        ms(u,0);
        ll done = 0;
        pii finish = mp(-1,-1);
        trav(i,NewTemp){
            if(i.size() == 3){
                i[1] *= -1;
                if(i[1] == 1 && Query(i[2],i[2])){
                    done = 1;
                }
                Ubah(i[2],i[1]);
            }else{
                if(Query(i[2],i[3]) || (i[0] == finish.first && i[2] <= finish.second)){
                    done = 1;
                }
                finish = mp(i[0],i[3]);
            }
            if(done){
                break;
            }
        }if(done){
            Upper = tengah;
        }else{
            lower = tengah;
        }
    }
    if(lower == N){
        cout << sum << "\n";
        return;
    }
    sum = 0;
    prevX = 0;
    prevY = 0;
    rep(i,0,lower-1){
        sum += B[i];
        prevX += arahX[i] * B[i];
        prevY += arahY[i] * B[i];
    }
    ll lower2 = 0, Upper2 = B[lower];
    while(Upper2 - lower2 >= 2){
        ll done = 0;
        ll tengah = (Upper2 + lower2)/2;
        rep(i,0,lower-1){
            vi tempV1 = {prevX,prevY,prevX + (arahX[lower] * (tengah-1)), prevY + (arahY[lower] * (tengah-1))};
            vi tempV2 = {tampungGaris[i].first.first,tampungGaris[i].first.second,tampungGaris[i].second.first,tampungGaris[i].second.second};
            if(tempV1[2] < tempV1[0]){
                swap(tempV1[2],tempV1[0]);
            }if(tempV1[3] < tempV1[1]){
                swap(tempV1[3],tempV1[1]);
            }if((max(tempV1[0],tempV2[0]) <= min(tempV1[2],tempV2[2])) && (max(tempV1[1],tempV2[1]) <= min(tempV1[3],tempV2[3]))){
                done = 1;
                break;
            }
        }
        if(done){
            Upper2 = tengah;
        }else{
            lower2 = tengah;
        }
    } 
    cout << sum + lower2<< "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    solve();
 
    return 0;
}