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

int ciclos[MAX];
vector<vector<pii>> g;
int depth[MAX];
int vis[MAX];
int dists[MAX];

void dfs(int u, int d, int prev){
    vis[u]=1;
    depth[u]=d;
    for (auto [v, w] : g[u]) {
        if (!vis[v]) dfs(v, d+w, u);
        else {
            if (v != prev) ciclos[v] = min(ciclos[v], d+w-depth[v]); 
        }
    }
}


int main(){ _
    int S, T; 
    while (cin >> S >> T){
        g.clear();
        g.resize(S+1);
        while (T--){
            int A, B, C; cin >> A >> B >> C;
            g[A].pb({B, C});
            g[B].pb({A, C});
        }
        
        int Q; cin >> Q;
        while (Q--){
            memset(depth, 0, sizeof depth);
            memset(vis, 0, sizeof vis);
            memset(ciclos, INF, sizeof ciclos);
            int X, M; cin >> X >> M;
            dfs(X, 0, X);
            int ans = INF;
            memset(dists, INF, sizeof dists);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({X, 0});
            while (!pq.empty()){
                auto [u, w] = pq.top();pq.pop();
                if (w > dists[u]) continue;
                dists[u]=w;
                for (auto [v, w_v]: g[u]){
                    pq.push({v, w_v+w});
                } 
            } 
            for (int i=1; i <= S; i++){
                if (ciclos[i] >= M and ciclos[i] != INF){
                    if (i == X) ans = min(ans, ciclos[i]);
                    else {
                        ans=min(ans, 2*dists[i]+ciclos[i]);
                    }
                }
            } 
            cout << (ans==INF ? -1 : ans) << endl;
        }
    }
    exit(0);
}
