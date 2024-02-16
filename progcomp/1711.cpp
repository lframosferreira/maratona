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

const int MAX = 1e4 + 10;
int vis[MAX];
int par[MAX];
vector<int> inits;

void dfs(int u, vector<vector<pii>> &g, int parent){
    if (vis[u]){
        inits.pb(u);
        return;
    }
    vis[u]=1;
    par[u]=parent;
    for (auto [v, w]: g[u]){ 
        if (!vis[v]) dfs(v, g, u);
    }
}

int main(){ _
    int S, T; 
    while (cin >> S >> T){
        vector<vector<pii>> g(S+1);
        while (T--){
            int A, B, C; cin >> A >> B >> C;
            g[A].pb({B, C});
            g[B].pb({A, C});
        }
        int Q; cin >> Q;
        while (Q--){
            memset(vis, 0, sizeof vis);
            memset(par, 0, sizeof par);
            inits.clear();
            int X, M; cin >> X >> M;
            dfs(X, g, X);
            cout << X << endl;
            for (int& i: inits) cout << i << " ";
            cout << endl;
        }
    }
    exit(0);
}
