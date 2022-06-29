// This code made by Muhammad Gilang Ramadhan

#include <bits/stdc++.h>
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

#define SIZE 100000
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int,int>> vpi;

void solve(){
    int T; cin >> T;
    vi Stack;
    vi inc;
    while(T--){
        int A; cin >> A;
        if(A == 1){
            int X; cin >> X;
            Stack.push_back(X);
            inc.push_back(0);
        }else if(A == 2){
            int Y,X; cin >> Y >> X;
            if(min(Y,(int)Stack.size()) - 1 >= 0)  inc[min(Y,(int)Stack.size()) - 1] += X;
        }else if(A == 0){
            if(Stack.size() - 1 > 0) inc[Stack.size() - 2] += inc[Stack.size() - 1];
            
            Stack.pop_back();
            inc.pop_back();
        }
        if(Stack.size() > 0){
            cout << Stack[Stack.size()-1] + inc[inc.size()-1] << " ";
        }else{
            cout << "EMPTY ";
        }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    solve();
 
    return 0;
}