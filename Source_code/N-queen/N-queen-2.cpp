#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define st first
#define nd second
#define file "test"
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) x.begin(), x.end()
const ll INF = 1e18;
const ll N = 2e6+7;
const ll mod = 1999999927;
const ll MOD = 1e9 + 7;
using namespace std;

//Khai bao bien o day ne thang lu 
ll n, dem = 0, a[10][10];
vector <pair<ll, ll>> ans;
int t[105][105];
set <vector<pair <ll, ll>>> fu;

bool OK(int x, int y){
    if (ans.empty()) return true;
    else{
        for (auto k : ans){
            if (k.st == x || k.nd == y || abs(k.st - x) == abs(k.nd - y)) return false;
        }
        return true;
    }
}

bool test(vector <pair<ll, ll>> x){
    for (auto q : fu){
        bool ch = false;
        for (int c = 0; c < n; c ++){
            if (x[c].st != q[c].st || x[c].nd != q[c].nd) ch = true;
        }
        if (ch == false) return false;
    }
    return true;
}

void check(){
    fu.insert(ans);
}


void fuck(ll x, ll y, ll val){
    t[x][y] += val;
    for (int k = 1; k < n; k ++){
        t[x][min(n + 1, y + k)] += val;
        t[x][max(0ll, y - k)] += val;
        t[min(n + 1, x + k)][y] += val;
        t[max(0ll, x - k)][y] += val;
        t[min(n + 1, x + k)][min(n + 1, y + k)] += val;
        t[min(n + 1, x + k)][max(0ll, y - k)] += val;
        t[max(0ll, x - k)][min(n + 1, y + k)] += val;
        t[max(0ll, x - k)][max(0ll, y - k)] += val;
    }
}

void ql(int x){
    for (int i = 1; i <= n; i ++){
        if (t[x][i] == 0){
            fuck(x, i, 1);
            ans.pb({x, i});
            if (x == n){
                check();
            }
            else ql(x + 1);

            ans.pop_back();
            fuck(x, i, -1);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(file".inp","r",stdin); freopen(file".out","w",stdout);
    #endif
    
    memset(t, 0, sizeof(t));
    
    cin >> n;
    ql(1);
    dem = fu.size();
    cout << dem;
    
    return 0;
}    
/* Hieulaptop_Here!!


*/


