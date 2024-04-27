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

int src, tgt;
pii par[MAX];
int gargalo;
bool vis[MAX];
vector<vector<Edge>> g;
vector<vector<Edge>> h;
queue<tuple<int, int, int>> edges;
bool cov[MAX][MAX];

bool bfs(int u){
    queue<pii> q;
    q.push({u, INF});
    vis[u]=true;
    while (!q.empty()){
        auto [v, curr_f]=q.front();q.pop();
        for (int i = 0; i < h[v].size(); i++){
            auto edg=h[v][i];
            if (edg.w <=0) continue;
            if (vis[edg.to]) continue;
            vis[edg.to]=true;
            int new_f=min(edg.w, curr_f);
            if (edg.to==tgt){
                par[edg.to]={v, i};
                gargalo=new_f;
                return true;
            }
            par[edg.to]={v, i};
            q.push({edg.to, new_f}); 
        }
    }
    return false;
}


int main(){ _
    int t; cin >> t;
    while (t--){
        int N, M; cin >> N >> M;
        g.clear();
        g.resize(N+1);
        memset(cov, false, sizeof cov);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            edges.push({u,v,c});
            }
        while (!edges.empty()){
            auto [u, v, c] = edges.front();edges.pop();
            if(cov[u][v]) continue;
            cov[u][v]=true;cov[v][u]=true;
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
                if (!bfs(src)) break;
                int aux_tgt=tgt;
                while (true){
                    auto [u, idx] = par[aux_tgt];
                    h[u][idx].w-=gargalo;
                    int rev_idx=h[u][idx].rev_idx;
                    h[aux_tgt][rev_idx].w+=gargalo;
                    aux_tgt=u;
                    if (aux_tgt==src) break;
                }
                ans+=gargalo;
            }
            resp=min(resp, ans);
        }
        cout << resp << endl;
    }    
    exit(0);
}
