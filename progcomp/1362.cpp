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

struct Edge {
    int to;
    int w;
    int rev_idx;
};

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
        vector<vector<Edge>> g(6+M+10);
        for (int i= 1; i <= M; i++){
            string a, b; cin >> a >> b; 
            int original_idx = g[6+i].size();
            int rev_idx = g[types[a]].size();
            g[types[a]].pb({6+i, 1, original_idx});
            g[6+i].pb({types[a], 0, rev_idx});

            original_idx = g[6+i].size();
            rev_idx = g[types[b]].size();
            g[types[b]].pb({6+i, 1, original_idx});
            g[6+i].pb({types[b], 0, rev_idx});
        }
        // adiciona arestas de inicio no src
        for (int i = 1; i <=6; i++) {
            int original_idx = g[src].size();
            int rev_idx = g[i].size();
            g[src].pb({i, N/6, rev_idx});
            g[i].pb({src, 0, original_idx});
        }
        // adiciona arestas de fim no tgt
        for (int i = 7; i <= 6 + M; i++){
            int original_idx = g[tgt].size();
            int rev_idx = g[i].size();
            g[tgt].pb({i, 0, rev_idx});
            g[i].pb({tgt, 1, original_idx});
        }

        // aplicar max flow e checar se ele é igual a M, se sim yes cc no
        while (1){
            dfs(src);
            if (aug_path.size()==0) break; 
            for (int i = 0; i < aug_path.size()-1; i++){
                g[i]     
            }
        }     
        cout << (ans == M ? "YES" : "NO") << endl;
    

    }
    exit(0);
}
