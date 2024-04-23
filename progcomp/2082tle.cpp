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

const int MAX = 110;

struct Edge {
    int to;
    int w;
    int rev_idx;
};

vector<pii> aug_path;
int gargalo;
int tgt, src;
bool found;
bool vis[MAX];

vector<vector<Edge>> g;
vector<vector<Edge>> h;

void dfs(int u){
    if (found) return;
    if (u==tgt) {
        found=true;
        return;
    }
    if (vis[u]) return;
    vis[u]=true;
    for (int j = 0; j < h[u].size(); j++){
        if(found) continue;
        auto [v, w, rev_idx]= h[u][j];
        if (w <= 0) continue;
        int prev=gargalo;
        gargalo=min(gargalo, w);
        aug_path.pb({u, j});
        dfs(v);
        if (!found){
            gargalo=prev;
            aug_path.pop_back();
        }
    }
}

int main(){ _
    int t; cin >> t;
    while (t--){
        int N, M; cin >> N >> M;
        g.clear();
        g.resize(N+1);
        h.clear();
        h.resize(N+1);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            g[u].pb({v, c, g[v].size()});
            g[v].pb({u, 0, g[u].size()-1});

            g[v].pb({u, c, g[u].size()});
            g[u].pb({v, 0, g[v].size()-1});
        }
        tgt=1; // smp 1
        int resp=INT_MAX;
        for (int k = 2; k <= N; k++){
            h.clear();
            h.resize(N+1);
            for (int i = 1; i <= N; i++) h[i].assign(g[i].begin(), g[i].end()); 
            src=k;
            int ans=0;
            while (1){
                memset(vis, false, sizeof vis);
                aug_path.clear();
                gargalo=INT_MAX;
                found=false;
                dfs(src);
                if (!found) break; 
                for (auto [u, idx] : aug_path){
                h[u][idx].w-=gargalo;
                int rev_idx=h[u][idx].rev_idx;
                h[h[u][idx].to][rev_idx].w+=gargalo;
                }
                ans+=gargalo;
            }
            resp=min(resp, ans);
        }
        cout << resp << endl;
    }    
    exit(0);
}
