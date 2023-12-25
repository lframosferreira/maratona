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

const int MAX = 1e5 +10;
vector<int> g[MAX];
int dists[MAX];

void dfs(int u){
    for(auto v:g[u]) if (dists[v] == -1) {
        dists[v] = dists[u]+1;
        dfs(v);
    }
}

int main(){ _
    int n;cin >> n;
    for (int i = 0;i< n-1;i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(dists, -1, sizeof(dists));
    dists[1] = 0;
    dfs(1);
    int idx = 1;
    int mxn = dists[1];
    for (int i = 2; i <= n; i++){
       if (dists[i] > mxn){
           mxn = dists[i];
           idx = i;
       } 
    }
    memset(dists, -1, sizeof(dists));
    dists[idx] = 0;
    dfs(idx);
    int ans = -INF;
    for (int i = 1; i<= n; i++){
        ans=max(ans, dists[i]);
    }
    cout << ans << endl;
    exit(0);
}
