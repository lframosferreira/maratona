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

const int MAX = 5e3 + 10;
vector<int> g[MAX];
stack<int> st;
bool vis[MAX];
bool good[MAX];
vector<pii> order;
int cnt;

void dfs1(int u){
    good[u] = true;
    for (auto v: g[u]){
        if (!good[v]) dfs1(v);
    }
}

void dfs2(int u){
    vis[u] = true;
    cnt++;
    for (auto v: g[u]){
        if (!vis[v] and !good[v]) dfs2(v);
    }
}

int main(){ _
    int n, m, s; cin >> n >> m >> s;
    int ui, vi;
    for (int i = 0; i < m; i++){
        cin >> ui >> vi;
        g[ui].pb(vi);
    }
    memset(vis, false, sizeof vis);
    memset(good, false, sizeof good);
    dfs1(s);
    for (int i = 1; i <= n; i++){
        cnt = 0;
        if (!good[i]) {
            memset(vis, false, sizeof vis);
            dfs2(i);
            order.pb({cnt, i});
        }
    }
    int ans = 0;
    sort(order.begin(), order.end(), greater<pii>());
    for (auto [aux, u] : order){
        if (good[u]) continue;
        ans++;
        dfs1(u);
    }
    cout << ans << endl;
    exit(0);
}
