// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define sz(v) (int)v.size()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef tuple<int, int, int> iii;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, M, A;

const int MAX = 1e4+5;

struct Edge {
    int to;
    int w;
    int rev_idx;
};

int src, tgt;
int gargalo;
bool vis[MAX];
vector<vector<Edge>> g;
int U;
vi level;
vector<iii> voos;

bool bfs(int u){
    level = vi(g.size()+1, -1);
    level[src]=0;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        auto v = q.front();q.pop();
        for (int i = 0; i < g[v].size(); i++){
            auto [to, w, rev_idx] = g[v][i];
            if (level[to]!=-1 or w < U) continue;
            level[to]=level[v]+1;
            q.push(to);
        }
    }
    return level[tgt]!=-1;
}

int dfs(int v, int f = INF) {
		if (!f or v == tgt) return f;
		for (int i = 0; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (level[e.to] != level[v] + 1) continue;
			int foi = dfs(e.to, min(f, e.w));
			if (!foi) continue;
			e.w -= foi, g[e.to][e.rev_idx].w += foi;
			return foi;
		}
		return 0;
}

int main(){ 
    while (true){
        cin >> N >> M >> A; 
        if (N == 0 and M == 0 and A == 0) break;
        U=-INF;
        g.clear();
        g.resize(MAX);
        voos.clear();
        while (M--){
            int O, D, S;
            cin >> O >> D >> S;
            voos.pb({O, D, S});
            U=max(U, S);
        }
        U|=U>>1;
        U|=U>>2;
        U|=U>>4;
        U|=U>>8;
        U|=U>>16;
        U = U ^ (U>>1);
        int lim = U;
        int ans=0;
        src=0;tgt=MAX-6;
        int dias=0;
        while (1){
            int idx=dias*N;

            g[src].pb({idx+1, A, sz(g[idx+1])});
            g[idx+1].pb({src, 0, sz(g[src])-1});

            g[N+idx].pb({tgt, A, sz(g[tgt])});
            g[tgt].pb({N+idx, 0, sz(g[N+idx])-1});
            
            for (int k = 1; k <= N; k++){
                g[idx+k].pb({idx+N+k, INF, sz(g[idx+N+k])});
                g[idx+N+k].pb({idx+k, 0, sz(g[idx+k]) - 1});
            }

            for (auto [O, D, S]: voos){
                g[idx+O].pb({idx+N+D, S, (int)g[idx+N+D].size()});
                g[idx+N+D].pb({idx+O, 0, (int)g[idx+O].size()-1});
            }
            
            int flow=0;
            for (U=lim;U;U>>=1){
                while (1){
                    if (!bfs(src)) break;
                    while (1){
                        gargalo = dfs(src);
                        if (gargalo==0) break;
                        flow+=gargalo;
                    }
                }
            }
            ans+=flow;
            dias++;
            if (ans >= A) break;
        }
        cout << dias-1 << endl; 
    }
    cout << endl;
    exit(0);
}
