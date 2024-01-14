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

vector<int> id, sz, xp, ex;

int find(int p){
    return id[p] == p ? p : find(id[p]);
}

void uni(int p, int q){
    p = find(p);
    q = find(q);
    if (p==q) return;
    if (sz[p] > sz[q]){
        int aux = p;
        p = q;
        q = aux;
    }
    id[p] = q;
    ex[p] = xp[q];
    sz[q] += sz[p];
}

int val(int p){
    return id[p] == p ? xp[p] : xp[p] - ex[p] + val(id[p]);
}

int main(){ _
    int n, m; cin >> n >> m;
    id.resize(n+1);
    ex.resize(n+1, 0);
    iota(id.begin(), id.end(), 0);
    sz.resize(n+1, 1);
    xp.resize(n+1, 0);
    string q; int x, y, v;
    while (m--){
        cin >> q;
        if (q=="add"){
            cin >> x >> v;
            xp[find(x)] += v;
        } else if (q=="join"){
            cin >> x >> y;
            uni(x, y);
        }else{
            cin >> x;
            cout << val(x) <<endl;
        }
    }
    exit(0);
}
