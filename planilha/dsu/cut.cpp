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

vector<int> sz, id;

int find(int p) {
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p);
    q = find(q);
    if (find(p)==find(q)) return;
    if (sz[p] > sz[q]){
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    sz[q] += sz[p];
}

int main(){ _
    int n, m, k; cin >> n >> m >> k;
    int u, v;
    id.resize(n+1);
    iota(id.begin(), id.end(), 0);
    sz.resize(n+1, 1);
    while (m--){
        cin >> u >> v;
    }
    string q;
    vector<tuple<int,int,int>> queries(k);
    for (int i = 0; i < k; i++){
        cin >> q >> u >> v;
        if (q=="cut"){
            queries[i] = {0, u, v};
        } else {
            queries[i] = {1, u, v};
        }
    }
    vector<int> ans;
    for (int i = k-1; i >= 0; i--){
        auto [que, a, b] = queries[i];
        if(que==0){
            uni(a,b);
        }
        else {
            if (find(a) == find(b)) ans.pb(1);
            else ans.pb(0);
        }
    }
    for (int i = ans.size() - 1; i>=0; i--) cout << (ans[i] ? "YES" : "NO") <<  endl;
    exit(0);
}
