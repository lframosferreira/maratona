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

vector<vector<int>> g;
bool vis[2010];
int cnt;

void dfs(int u){
    if (vis[u]) return;
    cnt++;
    vis[u]=true;
    for (auto v: g[u]) dfs(v);
}

int main(){ 
    while (true){
        int N, M; cin >> N >> M;
        if (N==0 and M==0) break;
        g.clear();
        g.resize(N+1);
        while (M--){
            int V, W, P; cin >> V >> W >> P;
            if (P==1) g[V].pb(W);
            else {
                g[V].pb(W);
                g[W].pb(V);
            }
        }
        bool ok=true;
        for (int i = 1; i <= N; i++) {
            memset(vis, false, sizeof vis); 
            cnt=0;
            dfs(i); 
            if (cnt!=N) {
                ok=false;
                break;
            }
        }
        if (ok) cout << 1 << endl;
        else cout << 0 << endl;
    } 
    exit(0);
}
