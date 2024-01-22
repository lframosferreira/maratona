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

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
int costs[MAX];
bool vis[MAX];
vector<int> g[MAX];
vector<int> grev[MAX];
stack<int> st;
int scc_val;
map<int, int> cnt;

void dfs(int u){
    if (vis[u]) return;
    vis[u] = true;
    for (auto v: g[u]) if(!vis[v]) dfs(v);
    st.push(u);
}

void dfs_rev(int u){
    if (vis[u]) return;
    vis[u] = true;
    cnt[costs[u]]++; 
    scc_val = min(scc_val, costs[u]);
    for (auto v: grev[u]) if (!vis[v]) dfs_rev(v);
}

int main(){ _
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> costs[i];
    int m; cin >> m;
    int u, v;
    while (m--){
        cin >> u >> v;
        g[u].pb(v);
        grev[v].pb(u);
    }
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        dfs(i);
    }
    scc_val = INF;
    ll price = 0;
    ll ways = 1;
    memset(vis, false, sizeof vis);
    while (!st.empty()){
        u = st.top();
        st.pop();
        if (vis[u]) continue;
        dfs_rev(u);
        price+=scc_val;
        ways = (ways % MOD * cnt[scc_val] % MOD) % MOD;
        scc_val=INF;
        cnt.clear();
    }
    cout << price << " " << ways << endl;
    exit(0);
}
