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

vector<int> id, sz;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if (p==q) return;
    if (sz[p] > sz[q]) {
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    sz[q] += sz[p];
}

int main(){ _
    int n, m; cin >> n >> m;
    id = vector<int>(n+2);
    sz = vector<int>(n+2, 1);
    iota(id.begin(), id.end(), 0);
    while (m--){
        string type;
       int u,v;
       cin >> type >> u >> v;
       if (type == "union"){
            uni(u, v);
       } else{
            if (find(u) == find(v)) cout << "YES" << endl;
            else cout << "NO" << endl;
       }
    }
    exit(0);
}
