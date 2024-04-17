// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

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

const int MAX = 2e5+10;
bool visited[MAX];
int d[MAX];

int mx;
void dfs(int u,int dist, vvi &g){
    if (visited[u]) return;
    visited[u]=true;
    d[u]+=dist;
    mx=max(mx, d[u]);
    for (auto v: g[u]){
        dfs(v, dist+1, g);
    }
}

int main(){ _
    int t; cin >> t;
    while (t--){
        mx=-INF;
        memset(d, 0, sizeof d);
        memset(visited, 0, sizeof visited);
        int n, k, c; cin >> n >> k >> c;
        vvi g(n+1, vi);
        for (int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vi ans(n+1);
        dfs(1, 0, g);
        dp[1]=mx;
    }    
    exit(0);
}
