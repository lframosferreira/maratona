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
    int n; cin >> n;
    while (n--){
        string txt; cin >> txt;
        int q; cin >> q;
        while (q--){
            string r; cin >> r;
            int p1=0;int p2=0;
            while (p1 < sz(txt) and p2 < sz(r)){
               if (txt[p1]==r[p2]){
               p1++;p2++;
               } else p1++;
            }
            cout << (p2 < sz(r) ? "No" : "Yes") << endl;
        }    
    }    
    exit(0);
}
