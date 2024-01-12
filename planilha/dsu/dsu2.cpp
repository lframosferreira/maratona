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

vector<int> sz, id, mx, mn;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p])); 
}

void uni(int p, int q){
   p = find(p);
   q = find(q);
   if (p==q) return;
   if (sz[p] > sz[q]){
        int aux = q;
        q = p;
        p = aux;
   }
   id[p] = q;
   mx[q] = max(mx[q], mx[p]);
   mn[q] = min(mn[q], mn[p]);
   sz[q] += sz[p];
}

int main(){ _
    int n, m; cin >> n >> m;
    sz.resize(n+1);
    id.resize(n+1);
    mx.resize(n+1);
    mn.resize(n+1);
    for (int i = 1; i <= n; i++){
        id[i] = i;
        sz[i]= 1;
        mx[i] = i;
        mn[i]= i;
    }
    string type;
    int u, v;
    while (m--){
        cin >> type;
        if (type == "get"){
            cin >> u;
            u = find(u);
            cout << mn[u] << " " << mx[u] << " " << sz[u] << endl;
        } else {
            cin >> u >> v;
            uni(u, v);
        }
    }
    exit(0);
}
