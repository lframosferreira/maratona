#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> g(n);

    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> vis(n, 0);

    vector<int> dm(n, 0);

    for(int i=0; i<n; i++){
        for(int j=0 ; j<n; j++) vis[j] = 0;

        vector<int> dist(n, INF);

        queue<pair<int,int>> q;

        dist[i] = 0;
        q.push({i, 0});

        while(!q.empty()){
            auto [u, w] = q.front(); q.pop();
            for(auto v: g[u]) if(!vis[v]){
                q.push({v, w+1});
                dist[v] = w+1;
                vis[v] = true;
            }
        }

        for(int j=0; j<n; j++) dm[i] = max(dm[i], dist[j]);
    }

    int mx = 0;
    for(int i=0; i<n; i++) mx = max(mx, dm[i]);

    int ans = max(0, 2*k+1 - mx);
    cout << ans << ' ' << ans << endl;

    exit(0);
}  
