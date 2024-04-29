// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 55;

bool vis[MAX];

int main(){ _
    int t; cin >> t;
    while (t--){
        memset(vis, false, sizeof vis);
        int n; cin >> n;
        vi v(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        int mn=INT_MAX;
        for (int i = 1; i <= n; i++){
            if (vis[i]) continue;
            int sz=0;
            vis[i]=true;
            int src=i;
            int aux=v[i];
            while (1){
                sz++;
                if (aux==src) break;
                vis[aux]=true;
                aux=v[aux];
            }
            mn=min(sz, mn);
        }
        cout << (mn == 2 ? 2 : 3) << endl;
    }
    exit(0);
}
