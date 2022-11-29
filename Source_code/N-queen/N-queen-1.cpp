#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define file "test"
#define all(x) x.begin(), x.end()
const ll INF = 1e18;
const ll N = 2e6+7;
using namespace std;

ll n, dem = 0;
vector <pair<ll, ll>> ans;
bool t[105][105];
vector <vector<pair <ll, ll>>> fu;

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
    sort(all(ans));
    if ((fu.empty())){
        fu.push_back(ans);
        dem++;
    }
    else{
        if (test(ans)){
            fu.push_back(ans);
            dem++;
        }
    }
}

void ql(int x){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (t[i][j] == false && OK(i, j) == true){
                t[i][j] = true;
                ans.push_back({i, j});
                if (x == n){
                    check();
                }
                else ql(x + 1);

                ans.pop_back();
                t[i][j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen(file".inp","r",stdin); freopen(file".out","w",stdout);
    #endif
    
    memset(t, false, sizeof(t));
    cin >> n;
    ql(1);
    cout << dem;

    
    return 0;
}    
/* Hieulaptop_Here!!


*/
