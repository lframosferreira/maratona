// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vi sze, id;

struct Edge {
    int u;
    int v;
    int c;

    bool operator < (const Edge &other){
        return c < other.c;
    }
};

int find(int u){
    return id[u] = (id[u] == u ? u : find(id[u]));
}

void uni(int u, int v){
    u=find(u);v=find(v);
    if (u==v) return;
    if (sze[v] < sze[u]){
        int aux = v;
        v = u;
        u = aux;
    }
    id[v]=u;
    sze[u]+=sze[v];
}

int main(){ _
    int N, M; cin >> N >> M;
    int O; cin >> O;
    id.resize(N+1);sze.resize(N+1, 1);
    iota(all(id), 0);
    vector<Edge> edg;
    for (int i = 0; i < M; i++){
        int U, V, D; cin >> U >> V >> D;
        edg.pb({U, V, D});
    }
    sort(all(edg));
    int ans=0; 
    for (auto& [u, v, c]: edg){
        if (find(u)==find(v))continue;
        uni(u, v);
        ans+=c;
    }
    cout << 2*ans << endl;
    exit(0);
}
