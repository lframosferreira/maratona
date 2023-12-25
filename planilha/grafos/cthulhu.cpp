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

const int MAX = 1e2 +10;
vector<int> g[MAX];
vector<bool> visited(MAX, false);

void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    for (auto v: g[u]){
        dfs(v);
    }
}

int main(){ _
    int n, m; cin >> n >> m;
    for (int i = 0; i< m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    if (n != m){
        cout << "NO" << endl;
    } else {
        dfs(1);        
        bool cond = true;
        for (int i = 1;i <= n;i++) cond = cond and visited[i];
        if (cond) cout << "FHTAGN!" << endl;
        else cout << "NO" << endl;
    }
    exit(0);
}
