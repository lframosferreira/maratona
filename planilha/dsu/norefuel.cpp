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

struct Edge {
    int u;
    int v;
    int w;
    bool operator < (const Edge &other){
        return w < other.w;
    }
};

vector<int> sz, id;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p,int q){
    p = find(p);
    q = find(q);
    if (p==q) return;

    if (sz[p]>sz[q]){
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    sz[q] += sz[p];

}

int main(){ _
    int n, k; cin >> n >> k;
    id.resize(n+1);
    iota(id.begin(), id.end(), 0);
    sz.resize(n+1, 0);
    vector<Edge> edg(k);
    vector<vector<pii>> g(n+1);
    int u, v, w;
    while (k--){
        cin >> u >> v >> w;
        edg.pb(Edge{u, v, w});
    }
    sort(edg.begin(), edg.end());
    int cnt= 0;
    int ans= -INF;
    for (auto e: edg){
       if (find(e.u) == find(e.v)) continue;
       uni(e.u, e.v);
       ans =max(ans, e.w);
       cnt++;
       if (cnt==n-1) break;
    }
    cout << ans << endl; 
    exit(0);
}
