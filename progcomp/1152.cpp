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

struct Edge{
    int u;
    int v;
    int w;

    bool operator < (const Edge &other){
        return w < other.w;
    }
};

const int MAX = 2e5 + 10;

int id[MAX], sz[MAX];

int find(int u){
    if (id[u]==u) return u;
    return id[u]=find(id[u]);
}

void uni(int p, int q){
    p=find(p);q=find(q);
    if (p==q) return;
    if (sz[p]>sz[q]){
        int aux = p;
        p=q;
        q=aux;
    }
    id[p]=q;
    sz[q]+=sz[p];
}

int main(){ _
    while (true){
        int n,m;cin>>n>>m;
        if (n==0 and m ==0) break;
        for (int i = 0; i <= n; i++) id[i]=i;
        for (int i = 0; i <= n; i++) sz[i]=1;
        vector<Edge> edges(m);
        int total = 0;
        for (int i = 0; i < m; i++){
            int x, y, z; cin >>x>>y>>z;
            edges[i]={x, y, z};
            total+=z;
        }
        int mst_total = 0;
        sort(edges.begin(), edges.end());
        for (auto e: edges){
            if (find(e.u)==find(e.v)) continue;
            mst_total+=e.w;
            uni(e.u, e.v);
        } 
        cout << total - mst_total << endl;
    }    
    exit(0);
}
