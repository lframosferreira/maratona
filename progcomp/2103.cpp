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
typedef unsigned long long ull;
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

const int MAX = 1e4+10;
const int MOD=1300031;

vector<vector<ii>> g;
ull ans;
int d[MAX];

void dfs(int u, int x){
    if (d[u] != -1) return;
    ans+=x%MOD;
    d[u]=x;
    for (auto [a, b] : g[u]) {
        if (d[a] != -1) continue;
        dfs(a, x+b);
    }
}

int main(){ _
    int N;
    int t; cin >> t;
    while (t--){
        cin >> N;
        g.clear();
        g.resize(N+1);
        for (int i = 0; i < N-1; i++){
            int u, v, w; cin >> u >> v >> w;
            g[u].pb({v, w});
            g[v].pb({u, w});
        }
        ans=0LL;
        for (int i = 1; i <= N; i++){
            for (int j =0; j < MAX; j++) d[j]=-1;
            dfs(i, 0);            
        }
        cout << ans/2 << endl;
    }    
    exit(0);
}
