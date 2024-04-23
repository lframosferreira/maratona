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
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110;
bool vis[MAX];
vector<vector<pii>> g;

int N, M;
vi A;
int s, t;

int minimum_cut_phase(){
    int mx_v=-1;
    int mx_w=-INF; 
    for (int i = 1; i <= N; i++){
        if (A[i]) continue;
        int total_w=0;
        for (auto [neigh, w] : g[i]) if (A[neigh]) total_w+=w;
        if (total_w > mx_w){
            mx_w=total_w;
            mx_v=i;
        }
    }
    A[mx_v]=1;

    return mx_w; // n sei se ta certo
}

int main(){ _
    int t; cin >> t;
    while (t--){
        cin >> N >> M;
        A.clear();
        A.resize(N+1);
        g.clear();
        g.resize(N+1);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            g[v].pb({u, c});
            g[u].pb({v, c});
        }
        int cnt=N;
        s=1;
        while (cnt>1){
            ans=min(ans, minimum_cut_phase());
        }
        cout << ans << endl;
    }    
    exit(0);
}
