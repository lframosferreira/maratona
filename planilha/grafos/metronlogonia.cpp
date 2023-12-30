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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// ideia: achardiametro de ambas estacoes e encontrar ponto medio delas. UNir os pontos medios
// // caso diametro impar:pegar a do meio
// // caso diametro par: pegar a mais longe da estação 1. como? n sei ainda

const int MAX = 1e5 + 10;
vector<int> circ[MAX];
vector<int> quad[MAX];

vector<int> dist;
vector<int> pred;

void dfscirc(int u, int d){
    if (dist[u] != -1) return;
    dist[u] = d;
    for (auto v : circ[u]){
        if (dist[v] == -1) pred[v] = u;
        dfscirc(v, d+1);
    }
}

void dfsquad(int u, int d){
    if (dist[u]!= -1) return;
    dist[u] = d;
    for (auto v : quad[u]){
        if (dist[v] == -1) pred[v] = u;
        dfsquad(v, d+1);
    }
}

int max_idx(vector<int> v, int s){
    int m = -INF;
    int idx = -1;
    for (int i = 1; i <= s; i++){
        if (dist[i] > m){
            m=dist[i];
            idx = i;
        }
    }
    return idx;
}

int main(){ 
    int n, m; cin >> n >> m;
    int u, v;
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        circ[u].pb(v);
        circ[v].pb(u);
    }
    for (int i = 0; i < m-1; i++){
        cin >> u >> v;
        quad[u].pb(v);
        quad[v].pb(u);
    }
    
    pred.resize(max(n, m)+1);
    dist.resize(max(n, m)+1);

    fill(pred.begin(), pred.end(), 0);
    fill(dist.begin(), dist.end(), -1);
    dfscirc(1, 0); 
    int idx1 = max_idx(dist, n);

    fill(pred.begin(), pred.end(), 0);
    fill(dist.begin(), dist.end(), -1);
    dfscirc(idx1, 0);
    int idx2 = max_idx(dist, n);
    
    for (int i = 0; i < dist[idx2]/2 + 1; i++)idx2=pred[idx2];
    
    cout << idx2 << " ";
    
    fill(pred.begin(), pred.end(), 0);
    fill(dist.begin(), dist.end(), -1);
    dfsquad(1, 0); 
    idx1 = max_idx(dist, m);

    fill(pred.begin(), pred.end(), 0);
    fill(dist.begin(), dist.end(), -1);
    dfsquad(idx1, 0);
    idx2 = max_idx(dist, m);
    for (int i = 0; i < dist[idx2]/2 + 1; i++)idx2=pred[idx2];
    
    cout << idx2 << endl;
    exit(0);
}
