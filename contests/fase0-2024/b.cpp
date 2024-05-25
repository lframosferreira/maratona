// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
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

const int MAX = 2e5+10;

vector<ii> g[MAX];
int vis[MAX];
int horas;
int N, M, K;
int cnt;

void dfs(int u){
    if (vis[u]) return;
    vis[u]=true;
    cnt++;
    for (auto [v, c]: g[u]) if (c <= horas) dfs(v);
}

int main(){ _
    cin >> N >> M >> K; 
    for (int i = 0; i < M; i++){
        int U, V, C;
        cin >> U >> V >> C;
        g[U].pb({V, C});
        g[V].pb({U, C});
    }
    int l = 0,r=8760;
    while (l < r){
        horas = (l+r)/2;
        memset(vis, 0, sizeof vis);
        cnt=0;
        dfs(1);
        if (cnt >= K) r=horas;
        else l=horas+1;
    }
    cout << l << endl;
    exit(0);
}
