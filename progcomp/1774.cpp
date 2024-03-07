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

const int MAX = 60 + 10;

int id[MAX];
int sz[MAX];

int find(int u){
    return id[u] = (id[u] == u ? u : find(id[u]));
}

void uni(int p, int q){
    p=find(p);
    q=find(q);
    if (sz[p]>sz[q]){
        int aux = p;
        p=q;
        q=aux;
    }
    id[p]=q;
    sz[q]+=sz[p];
}

int main(){ _
    for (int i = 0; i < MAX; i++) id[i]=i;
    for (int i = 0; i < MAX; i++) sz[i]=1;
    int R, C; cin >> R >> C;
    vector<Edge> edges(C);
    for (int i = 0; i < C; i++){
        int V, W, P; cin >>  V >> W >> P;
        edges[i]={V, W, P};
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    int ans = 0;
    for (auto e : edges){
        if (find(e.u)==find(e.v)) continue; 
        cnt++;
        ans+=e.w;
        uni(e.u, e.v);
        if (cnt==R-1) break;
    }
    cout << ans << endl;
    exit(0);
}
