// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int t; cin >> t;
    while (t--){
        string b;cin >> b;
        int ztoo=0, otoz=0;
        int cgs=0;
        for (int i = 0;i < sz(b)-1; i++){
            if (b[i]!=b[i+1]){
                cgs++;    
                if (b[i]=='1') otoz=1;
                else ztoo=1; 
            } 
        }
        if (!ztoo){
            cout << (otoz ? 2 : 1) << endl;
        }else {
            cout << (cgs==1 ? 1 : cgs) <<endl;
        }
    }    
    exit(0);
}
