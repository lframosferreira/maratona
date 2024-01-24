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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e4 + 10;
vector<int> g[MAX];
int dgs[MAX];
int vis[MAX];

int ans;
int c, start;

int dfs1(int u){
    if (vis[u]) return -1;
    vis[u] = true;
    if (dgs[u] > 2 and u!= c) return u;    
    for (auto v: g[u]) return dfs1(v);
}

void dfs2(int u, int dist){
    if (u==c) return;
    if (u==start) ans=max(ans, dist);
    if (vis[u]) return;
    vis[u] = true;
    for (auto v: g[u]) if (v!=c) dfs2(v, dist+1);
}

int main(){ _
    memset(dgs, 0, sizeof dgs);
    memset(vis, 0, sizeof vis);
    ans = -INF;
    int N, M; cin >> N >> M;
    while (M--){
        int P, Q; cin >> P >> Q;
        g[P].pb(Q);
        g[Q].pb(P);
        dgs[P]++;
        dgs[Q]++;
    }
    c = -1;
    for (int i = 1; i <= N; i++) {
        if (dgs[i] >= 5){
            c = i;
        }
    }
    start = dfs1(c);
    memset(vis, 0, sizeof vis);
    dfs2(start, 0);
    cout << ans << endl;
    exit(0);
}
