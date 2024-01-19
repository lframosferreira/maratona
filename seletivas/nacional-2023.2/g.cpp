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

vector<bool> vis;
vector<vector<int>> g;

void dfs(int u){
    if (vis[u]) return;
    vis[u] = true;
    for (auto v : g[u]){
        if (!vis[v]) dfs(v);
    }
}

int main(){ _
    int n, m; cin >> n >> m;
    vis.resize(n+m+10, false);
    g.resize(n+m+10, vector<int>());
    vector<int> alone;
    int aux_lang = n+1;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        if (k==0){
            alone.pb(i);
            continue;
        }
        int lang;
        while (k--){
            cin >> lang;
            lang+=n+1;
            g[i].pb(lang);
            g[lang].pb(i);
            aux_lang = lang;
        }
    }
    int ans = 0;
    for (int i: alone) {
        g[i].pb(aux_lang);
        g[aux_lang].pb(i);
        ans++;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        dfs(i);
        ans++;
    }
    cout << ans-1 << endl;
    exit(0);
}
