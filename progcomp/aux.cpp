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
    bool is_rev;
};

int N, M;
int src, tgt;
bool found_tgt;
int gargalo;
vector<vector<Edge>> g;
vector<pii> aug_path;
int cov[MAX][MAX];
int U;
vi level;

bool bfs(int u){
    level = vi(g.size()+1, -1);
    level[src]=0;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        auto v = q.front();q.pop();
        for (int i = 0; i < g[v].size(); i++){
            auto [to, w, rev_idx, is_rev] = g[v][i];
            if (level[to]!=-1 or w < U) continue;
            level[to]=level[v]+1;
            q.push(to);
        }
    } 
    return level[tgt]!=-1;
}

vector<pii> par;
bool bfs2(int u){
    par=vector<pii>(g.size()+1, {-1, -1});
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        auto v=q.front();q.pop();
        for (int i = 0; i < g[v].size(); i++){
            auto edg=g[v][i];
            if (level[edg.to]!=level[v]+1) continue;
            if (edg.w <=0) continue;
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

void reset_g(){
    for (int i = 1; i <= N;i++){
        for (int j = 0; j < g[i].size(); j++){
            auto [to, w, rev_idx, is_rev] = g[i][j];
            if (is_rev){
                g[to][rev_idx].w+=w;
                g[i][j].w=0; 
            }
        }
    }
}

void print_g(){
    for (int i = 1; i <= N;i++){
        cout << i <<endl;
        for (int j = 0; j < g[i].size(); j++){
            auto [to, w, rev_idx, is_rev] = g[i][j];
            cout << "to: " << to << " w: " << w << " " << is_rev << endl;
           }
        cout << "--------" << endl;
    }
}

void print_level(){
    for (int i = 1; i <= N; i++){
        cout << level[i] << " ";
    }
    cout << "\n----------------" << endl;
}

stack<tuple<int, int, int>> edges;

int main(){ 
    int t; cin >> t;
    while (t--){
        cin >> N >> M;
        g.clear();
        g.resize(N+1);
        memset(cov, 0, sizeof cov);
        U=-INF;
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            U=max(U, c);
            edges.push({u,v,c});
        }
        U|=U>>1;
        U|=U>>2;
        U|=U>>4;
        U|=U>>8;
        U|=U>>16;
        U = U ^ (U>>1);
        int lim=U;
        while (!edges.empty()){
            auto [u, v, c] = edges.top();edges.pop();
            if(cov[u][v] or cov[v][u]) continue;
            cov[u][v]=1;cov[v][u]=1;
            g[u].pb({v, c, (int)g[v].size(), false});
            g[v].pb({u, 0, (int)g[u].size()-1, true});

            g[v].pb({u, c, (int)g[u].size(), false});
            g[u].pb({v, 0,(int)g[v].size()-1, true});
        }
        src=1; // smp 1
        int resp=INT_MAX;
        for (int k = 2; k <= N; k++){
            if (k!=2) reset_g();
            tgt=k;
            int ans=0;
            for (U=lim;U;U>>=1){
                while (1){
                    if (!bfs(src)) break;
                    while (1){
                        if (!bfs2(src)) break;
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
                }
            }
            if (ans!=0) resp=min(resp, ans);
        }
        cout << resp << endl;
    }    
    exit(0);
}