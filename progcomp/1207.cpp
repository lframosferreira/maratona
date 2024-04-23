// pescoço pra baixo é canela
//

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

const int MAX = 1010;

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

bool bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    
    while (!q.empty()){
        auto v=q.front();q.pop();
        for (int i = 0; i < g[v].size(); i++){
            auto edg=g[v][i];
            if (edg.w <=0) continue;
            if (vis[edg.to]) continue;
            vis[edg.to]=true;
            if (edg.to==tgt){
                par[edg.to]={v, i};
                return true;
            }
            par[edg.to]={v, i};
            q.push(edg.to);
        }
    }
    return false;
}

int N, M;
int custos_vodka[610];
int beneficios[610];
int aux[410];

void print_g(){
    for (int i = 0; i <= N+M+1 ; i++){
        dbg(i);
        for (auto edg: g[i]){
            dbg(edg.to);dbg(edg.w);
        }
        cout << "--------------" << endl;
    }
}

int main(){
    while (cin >> N >> M){
        int total_b=0;
        g.clear();
        g.resize(N+M+5);
        for (int i = 1; i <= N; i++) cin >> custos_vodka[i];
        for (int i= 1; i <= M; i++) cin >> aux[i];
        src=0;
        tgt=N+M+1;
        for (int i = 1; i <= M; i++){
            cin >> beneficios[i]; 
            total_b+=beneficios[i];
            for (int j = 0; j < aux[i]; j++){
                int vod;cin >> vod;
                g[i].pb({M+vod, INF, g[M+vod].size()});
                g[M+vod].pb({i, 0, g[i].size()-1});
            }
        }
        for (int i = 1; i <= M; i++){
            g[src].pb({i, beneficios[i], g[i].size()});
            g[i].pb({src, 0, g[src].size()-1});
        }
        for (int i = 1; i <= N; i++){
            g[i+M].pb({tgt, custos_vodka[i], g[tgt].size()}); 
            g[tgt].pb({i+M, 0, g[i+M].size()-1});
        }

        int ans=0;
        int cnt=0;
        while (1){
            memset(vis, false, sizeof vis);
            if (!bfs(src)) break;
            int aux_tgt=tgt;
            gargalo=INT_MAX;
            while (true){
                gargalo=min(gargalo, g[par[aux_tgt].f][par[aux_tgt].s].w);
                aux_tgt=par[aux_tgt].f;
                if (aux_tgt==src) break;
            }
            aux_tgt=tgt;
            while (true){
                auto [u, idx] = par[aux_tgt];
                g[u][idx].w-=gargalo;
                int rev_idx=g[u][idx].rev_idx;
                g[aux_tgt][rev_idx].w+=gargalo;
                aux_tgt=u;
                if (aux_tgt==src) break;
            }
            cnt++;
            ans+=gargalo;
        }
        cout << total_b-ans << endl;
    }
    exit(0);
}
