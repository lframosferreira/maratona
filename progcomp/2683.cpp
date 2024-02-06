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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3 + 10;

struct Edge {
    int u;
    int v;
    int w;

    bool operator < (const Edge &other) {
        return w < other.w;
    };
};

int id[MAX], sz[MAX];
vector<Edge> edges;

int find(int p) {
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p); q=find(q);
    if (p==q) return;
    if (sz[p] > sz[q]){
        int aux = p;
        p = q;
        q = aux;
    }
    id[p]=q;
    sz[q]+=sz[p];
}

int main(){ _
    int N; cin >> N;
    int u, v, w;
    while (N--){
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    sort(edges.begin(), edges.end());
    int mn = 0;
    int mx = 0;
    for (int i = 1; i < MAX; i++) {
        sz[i] = 1;
        id[i] = i;
    }
    for (auto e: edges){
        if (find(e.u)==find(e.v)) continue;
        uni(e.u, e.v);
        mn+=e.w;
    }
    for (int i = 1; i < MAX; i++) {
        sz[i] = 1;
        id[i] = i;
    }
    reverse(edges.begin(), edges.end());
    for (auto e: edges){
        if (find(e.u)==find(e.v)) continue;
        uni(e.u, e.v);
        mx+=e.w;
    }
    cout << mx << endl;
    cout << mn << endl;
    exit(0);
}
