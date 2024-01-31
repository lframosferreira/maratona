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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 26 + 5;
vector<vector<int>> g;
int vis[MAX];
vector<int> cc_nodes;

void dfs(int u){
    if (vis[u]) return;
    vis[u] = 1;
    cc_nodes.pb(u);
    for (auto v: g[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main(){ _
    int N; cin >> N;
    for (int Case = 1; Case <= N; Case++){
        memset(vis, 0, sizeof vis);
        int V, E; cin >> V >> E;
        g.clear();
        g.resize(V+1);
        while (E--){
            char u, v; cin >> u >> v;
            g[(int)(u - 'a')].pb((int)(v - 'a'));
            g[(int)(v - 'a')].pb((int)(u - 'a'));
        }
        cout << "Case #" << Case << ":" << endl;
        int cc = 0;
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            cc_nodes.clear();
            dfs(i);
            sort(cc_nodes.begin(), cc_nodes.end());
            for (auto v: cc_nodes) cout << (char)(v+'a') << ",";
            cout << endl;
            cc++;
        }
        cout << cc << " connected components" << endl << endl;
    }
    exit(0);
}
