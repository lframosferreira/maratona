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
typedef vvi vector<vi>
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edge{
    int to;
    int w;
    int rev_id;
};

int flow=0;

int main(){ _
    int n,m,k;
    int cnt=1;
    while (cin >> n >>m >> k){
        // cavalos de 1 ate n 
        // soldados d en+1 ate m+n
        vector<vector<pii>> g(n+m+5);
        int src=0;
        int tgt=n+m+1;
        for (int i = 1; i <= n; i++) {
                int aux; cin >> aux;
                g[src].pb({i, aux});
        }
        while (k--){
            int u,v;cin>>u>>v;
            g[u].pb({v, 1});
        }

        
        // APLICAR FLOYWD WARSHALL
        cout << "Instancia " << cnt << endl;
        cout << flow << endl;
        cnt++;
    }
    exit(0);
}
