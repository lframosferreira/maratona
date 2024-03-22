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
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edge{
    int to;
    int w;
    int rev_idx;
};

int src, tgt;
int gargalo;
vector<pii> aug_path;
bool vis[250];
bool found_tgt;
vector<vector<Edge>> g;

void dfs(int u){
    if (found_tgt) return;
    if (u==tgt){
        found_tgt=true;
        return;
    }
    if (vis[u]) return;
    vis[u]=true;

    for (int j = 0; j < g[u].size(); j++){
        if (found_tgt) return;
        auto [v, w, rev_idx] = g[u][j];
        if (w <= 0) continue;
        int prev=gargalo;
        gargalo=min(gargalo, w);
        aug_path.pb({u, j});
        dfs(v);
        if (!found_tgt){
            gargalo=prev;
            aug_path.pop_back();
        }
    }
}

int main(){ _
    int n,m,k;
    int cnt=1;
    while (cin >> n >>m >> k){
        // cavalos de 1 ate n 
        // soldados de n+1 ate m+n
        g.clear();
        g.resize(n+m+5);
        src=0;
        tgt=n+m+1;
        for (int i = 1; i <= n; i++) {
                int aux; cin >> aux;
                g[src].pb({i, aux, (int)g[i].size()});
                g[i].pb({src, 0, (int)g[src].size()-1});
        }
        
        for (int i = 1; i <= m; i++){
            g[i+n].pb({tgt, 1, (int)g[tgt].size()});
            g[tgt].pb({i+n, 0, (int)g[i+n].size()-1});
        }

        while (k--){
            int u,v;cin>>u>>v;
            g[u].pb({v+n, 1, (int)g[v+n].size()});
            g[v+n].pb({u, 0, (int)g[u].size()-1});
        }
        
        int flow=0;
        while (1){ 
            memset(vis, false, sizeof vis);
            gargalo=INT_MAX;
            aug_path.clear();
            found_tgt=false;
            dfs(src);
            if (!found_tgt) break;
            for (auto [u, idx]: aug_path){
                g[u][idx].w-=gargalo;
                g[g[u][idx].to][g[u][idx].rev_idx].w+=gargalo;
            }
            flow+=gargalo;
        }
        cout << "Instancia " << cnt << endl;
        cout << flow << endl << endl;;
        cnt++;
    }
    exit(0);
}
