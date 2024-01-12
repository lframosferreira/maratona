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
vector<vector<int>> filhos;
vector<int> ans;
vector<bool> vis;

int find(int p){
    return id[p] == p ? p : find(id[p]);
}

void uni(int p, int q){
    p = find(p);
    q = find(q);
    if (sz[p] > sz[q]){
       int aux = p;
       p = q;
       q = aux;
    }
    id[p] = q;
    filhos[q].pb(p);
    sz[q] += sz[p];
}

void dfs(int x){
    if (vis[x]) return;
    vis[x] = true;
    ans.pb(x);
    for (auto f: filhos[x]){
       dfs(f); 
    }
}

int main(){ _
    int n; cin >> n;
    id.resize(n+1);
    sz.resize(n+1);
    filhos.resize(n+1);
    vis.resize(n+1, false);
    for (int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }
    int x, y;
    for (int i = 0; i < n-1;i++){
        cin >> x >> y;
        uni(x, y);
    }
    int root = -1;
    for (int i = 1; i <= n; i++){
        if (i == id[i]){
            root=i;
            break;
        }
    }
    dfs(root);
    for (auto e: ans) cout << e << " ";
    cout << endl;
    exit(0);
}
