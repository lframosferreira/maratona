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

const int MAX = 2e5 + 10;

int main(){ _
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n+1);
        while (m--){
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        queue<pii> q;
        q.emplace(1, 0);
        vector<int> odd;
        vector<int> even;
        vector<bool> vis(n+1, false);
        while (!q.empty()){
            auto [u, w] = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            if (w%2 == 0) even.pb(u);
            else odd.pb(u);
            for (auto v :g[u]){
                q.emplace(v, w+1);
            }
        }
        if (even.size() > odd.size()){
            cout << odd.size() << endl;
            for (auto e: odd) cout << e << " ";
            cout << endl;
        }else{
            cout << even.size() << endl;
            for (auto e: even) cout << e << " ";
            cout << endl;
        }
    }
    exit(0);
}
