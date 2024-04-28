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
bool vis[MAX];
int allowed[MAX][MAX];
vector<vector<Edge>> g;
vector<pii> aug_path;
bool found_tgt_bfs;

bool bfs(int u){
    queue<pii> q;
    q.push({u, u});
    while (!q.empty()){
        auto [v, from] = q.front();q.pop();
        if(vis[v] and v!= tgt)continue;
        vis[v]=true;
        allowed[from][v]=1;
        for (int i = 0; i < g[v].size(); i++){
            auto [to, w, rev_idx, is_rev] = g[v][i];
            if (vis[to] or w <= 0) continue;
            if (to==tgt) found_tgt_bfs=true;
            q.push({to, v});
        }
    } 
    return found_tgt_bfs;
}

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
        auto [v, w, rev_idx, is_rev] = g[u][j];
        if(!allowed[u][v]) continue;
        if (w<=0) continue;
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

void print_allowed(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){    
            cout << allowed[i][j] << " ";
        }
        cout<< endl;
    }
    cout << "----------------" << endl;
}

int main(){ 
    int t; cin >> t;
    while (t--){
        cin >> N >> M;
        g.clear();
        g.resize(N+1);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            g[u].pb({v, c, (int)g[v].size(), false});
            g[v].pb({u, 0, (int)g[u].size()-1, true});

            g[v].pb({u, c, (int)g[u].size(),false});
            g[u].pb({v, 0, (int)g[v].size()-1, true});
        }
        src=1; // smp 1
        int resp=INT_MAX;
        for (int k = 2; k <= N; k++){
            reset_g();
            tgt=k;
            int ans=0;
            while (1){
                cout << "*******" << endl;
                memset(vis, false, sizeof vis);
                memset(allowed, 0, sizeof allowed);
                found_tgt_bfs=false;
                if (!bfs(src)) break;
                print_allowed();
                while (1){
                    memset(vis, false, sizeof vis);
                    found_tgt=false;
                    gargalo=INT_MAX;
                    aug_path.clear();
                    dfs(src);
                    if (!found_tgt) break;
                    for (auto [u, idx]: aug_path){
                        g[u][idx].w-=gargalo;
                        g[g[u][idx].to][g[u][idx].rev_idx].w+=gargalo;
                    }
                    ans+=gargalo;
                }
            }
            if (ans!=0) resp=min(resp, ans);
        }
        cout << resp << endl;
    }    
    exit(0);
}
