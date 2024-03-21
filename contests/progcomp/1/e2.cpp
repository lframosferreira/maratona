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

const int MAX = 2e6 + 10;

int id[MAX], sz[MAX];

struct Edge{
    int u;
    int v;
    ll w;

    bool operator < (const Edge &other){
        return w < other.w;
    }
};

int find(int u){
    return id[u] = (id[u]==u ? u : find(id[u]));
}

void uni(int p, int q){
    p=find(p);q=find(q);
    if(p==q) return;
    if (sz[p] > sz[q]){
        int aux=p;
        p=q;
        q=aux;
    }
    id[p]=q;
    sz[q]+=sz[p];
}

int main(){ _
    int n, m; cin >> n >> m;
    vector<ll> c(n+1);
    for (int i = 1; i <= n; i++){
        id[i]=i;
        sz[i]=1;
    }
    for (int i=1; i <= n; i++) cin >> c[i];
    int mn = c[1];
    int idx=1;
    for (int i = 2; i <= n; i++){
        if (c[i] < mn){
            mn=c[i];
            idx=i;
        }
    }
    vector<Edge> edges;
    for (int i = 1; i <= n; i++){
        if (i==idx) continue;
        edges.pb({i, idx, c[i]+c[idx]});
    }
    while (m--){
        int i, j; ll r; cin >> i >> j >> r;
        edges.pb({i, j, r});
    }
    sort(edges.begin(), edges.end()); 
    ll ans=0;
    for (auto e : edges){
        if (find(e.u)==find(e.v)) continue;
        uni(e.u, e.v);
        ans+=e.w;
    }
    cout << ans << endl;
    exit(0);
}
