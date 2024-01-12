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

    bool operator < (const Edge& e){
        return w < e.w;
    }
};

vector<int> sz, id;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p);
    q = find(q);
    if (p==q) return;
    if (sz[p] > sz[q]){
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    sz[q] += sz[p];
}

int main(){ _
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    id.resize(n+1);
    sz.resize(n+1);
    for (int i = 1; i <= n; i++){
        sz[i] = 1;
        id[i] = i;
    }
    int u, v, w;
    int idx = 0;
    while (m--){
        cin >> u >> v >> w;
        edges[idx] = {u, v, w};
        idx++;
    }
    sort(edges.begin(), edges.end());
    int cnt_e = 0;
    ll ans = 0;
    for (auto e: edges){
       if (find(e.u) == find(e.v)) continue;
        ans += e.w;
        cnt_e+=1;
        uni(e.u, e.v);
        if (cnt_e == n-1) break;
    }
    cout << ans << endl;
    exit(0);
}
