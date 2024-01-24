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
int u, ans, extra;

void dfs(int y, int dist){
    if (vis[y]){
        ans = max(ans, dist); 
        return;
    }
    vis[y] = true;
    for (auto v: g[y]){
        dfs(v, dist=1);
    }
}

int main(){ _
    memset(dgs, 0, sizeof dgs);
    memset(vis, 0, sizeof vis);
    u = -1;
    ans = -INF;
    int N, M; cin >> N >> M;
    while (M--){
        int P, Q; cin >> P >> Q;
        g[P].pb(Q);
        g[Q].pb(P);
        dgs[P]++;
        dgs[Q]++;
    }
    for (int i = 1; i <= N; i++){
        if (dgs[i] == 1){
            u = i;
            break;
        }
    }
    if (u == -1){
        for (int i = 1; i <= N; i++){
            if (dgs[i] == 3){
                u = i;
                break;
            }
        }
    }
    extra = 0;
    while (dgs[u] < 3){
        extra++;
        u = g[u][0];
    }
    dfs(u, 0);
    cout << ans << endl;
    exit(0);
}
