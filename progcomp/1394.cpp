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

const int MAX = 45;

struct Edge{
    int to;int w; int rev_idx;
};

int N, M, G;
int src, tgt;
pii par[3010];
int gargalo;
bool vis[3010];
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

int games[MAX][MAX];
int pnts[MAX];

void setup(){
    memset(pnts, 0, sizeof pnts);
    memset(games, 0, sizeof games);
    g.clear();g.resize(3010);
    for (int i = 0; i < N; i++){
        for (int j=i+1; j < N; j++){
            games[i][j]=M;
        }
    }
}

int main(){ _
    while (1){
        cin >>N >> M >> G;
        if(N==0) break;
        int total=0;
        setup();
        while (G--){
            char r; int i, j;
            cin >> i >>r>> j;
            if(j > i) games[i][j]--;
            else games[j][i]--;
            if (r=='<'){
                pnts[j]+=2;
            } else {
                pnts[i]++;pnts[j]++;
            }
        }
        // da vitoria pra todos os jogos de 0
        for (int j=1; j < N; j++) {
            pnts[0]+=games[0][j]*2;
            games[0][j]=0;
        }

        tgt=N;
        src=0;

        // checa se da pra pra continuar
        bool isbig=true;
        for (int j = 1; j < N; j++){
            if (pnts[j]>=pnts[0]){
                isbig=false;
                break;
            }
        }
        if(!isbig){
            cout << "N" << endl;
            continue;
        }

        // cria grafo
        //src -> confronto: nro de jogos do confronto*2
        // confronto ->times : inf
        // times: limite calculado posteriormente
        int gms_id=N+1;
        for (int i = 1; i < N; i++){
            for (int j = i+1;j < N; j++){
                if (games[i][j]){
                    int w=games[i][j]*2;
                    total+=w;
                    g[src].pb({gms_id, w, (int)g[gms_id].size()}); 
                    g[gms_id].pb({src, 0, (int)g[src].size()-1});

                    g[gms_id].pb({i, INF, (int)g[i].size()});
                    g[i].pb({gms_id, INF, (int)g[gms_id].size()});

                    g[gms_id].pb({j, INF, (int)g[j].size()});
                    g[j].pb({gms_id, INF, (int)g[gms_id].size()});

                    gms_id++;
                }
            }
        }

        // cria arestas do tgt
        for (int i = 1; i < N; i++){
            g[i].pb({tgt, pnts[0]-pnts[i]-1, (int)g[tgt].size()});  
            g[tgt].pb({i,0, (int)g[i].size()});  
        }

        // roda fluxo a partir de 1
        int ans=0; 
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
            ans+=gargalo;
        }
        if (ans < total) cout << "N" <<endl;
        else cout << "Y" << endl;
    } 
    exit(0);
}
