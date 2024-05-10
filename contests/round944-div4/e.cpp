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

int main(){ 
    int t; cin >> t;
    while (t--){
        int n, k, q; cin >> n >> k >> q;
        vll a(k+1), b(k+1);
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];
        while (q--){
            int d; cin >> d;
            if (d==0){
                cout << 0 << " ";
                continue;
            }
            if (d==n){
                cout << b[k] <<  " ";
                continue;
            }
            int p = distance(a.begin(), upper_bound(all(a), d));
            ll dist = a[p]-a[p-1];
            ll time = b[p]-b[p-1];
            cout << b[p-1] + ((d - a[p-1])*(time))/dist  << " ";
        }
        cout << endl;
    }    
    exit(0);
}
