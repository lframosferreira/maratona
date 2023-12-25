// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
vector<int> g[MAX];
int cat[MAX];
int dgs[MAX];
int vis[MAX];

int ans = 0;

void dfs(int u, int cnt, int m){
    if (vis[u]) return;
    vis[u] = true;
    if (cnt == m+1) return;
    if (dgs[u] == 1 && u != 1) {ans++; return;}
    for (auto v: g[u]){
        if (cat[v]) dfs(v, cnt+cat[v], m);
        else dfs(v, 0, m);
    }
}

int main(){ _
    int n, m; cin >>n >> m;
    memset(dgs, 0, sizeof dgs); 
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n;i++){
        cin >> cat[i];
    }
    for (int i = 0; i< n-1;i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        dgs[u]++;
        dgs[v]++;
    }
    dfs(1, cat[1], m); 
    cout << ans << endl;
    exit(0);
}
