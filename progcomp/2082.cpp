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
vector<vector<Edge>> g;

vi A;

int minimum_cut_phase(){
    
}

int main(){ _
    int t; cin >> t;
    while (t--){
        int N, M; cin >> N >> M;
        g.clear();
        g.resize(N+1);
        for (int i = 0; i < M; i++){
            int u, v, c; cin >> u >> v >> c;
            g[v].pb({u, c});
            g[u].pb({v, c});
        }
        int cnt=N;
        while (cnt>1){
            ans=min(ans, minimum_cut_phase());
        }
        cout << ans << endl;
    }    
    exit(0);
}
