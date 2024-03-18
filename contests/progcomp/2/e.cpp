// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;

struct Edge {
    int u;
    int v;
    int w;

    bool operator < (const Edge &other){
        return w < other.w;
    };
};

int id[MAX], sz[MAX];

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if (p==q) return;
    if (sz[p] > sz[q]) {
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    sz[q] += sz[p];
}

int main(){ _
    int n, m; cin >> n >> m;
    memset(sz, 1, sizeof sz);
    for (int i = 1; i <= n; i++) id[i]=i;
    vector<Edge> edges;
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    int k=0;
    set<int> used_weights;
    vector<bool> used(edges.size());
    for (int i = 0; i < edges.size(); i++){
        auto e = edges[i];
        if (find(e.u)==find(e.v)) continue;
        uni(e.u, e.v);
        k+=e.w;
        used[i]=true;
        used_weights.insert(e.w);
    } 
    int ans=0;
    for (int i = 0; i < edges.size(); i++){
        if (used[i]) continue;
        int aux=edges[i].w;
        while (used_weights.find(aux) != used_weights.end()){
            aux++;
        }
        ans+=aux-edges[i].w;
    }
    cout << ans << endl;

    exit(0);
}
