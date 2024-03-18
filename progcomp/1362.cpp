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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    _ int t;
    cin >> t;
    map<string, int> types;
    types["XXL"]=1;
    types["XL"]=2;
    types["L"]=3;
    types["M"]=4;
    types["S"]=5;
    types["XS"]=6;
    while (t--) {
        int N, M;
        cin >> N >> M;
        int src=0;
        int tgt=6+M+1;
        vector<vector<pii>> g(6+M+10);
        for (int i= 1; i <= M; i++){
            string a, b; cin >> a >> b; 
            g[types[a]].pb({6+i, 1});
            g[types[b]].pb({6+i, 1});
        }
        // adiciona arestas de inicio no src
        for (int i = 1; i <=6; i++) g[src].pb({i, N/6});
        // adiciona arestas de fim no tgt
        for (int i = 7; i <= 6 + M; i++) g[i].pb({tgt, 1});

        // aplicar max flow e checar se ele é igual a M, se sim yes cc no
    }
    exit(0);
}
