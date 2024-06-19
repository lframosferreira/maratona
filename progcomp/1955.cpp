// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3+5;
vector<int> g[MAX];
int c[MAX];
int ok;

void dfs(int u, int color){
    if (c[u]) return;
    c[u]=color;
    for(auto v: g[u]){
        if (c[v] and c[v]==color){
            ok=false;
        }else if (c[v])continue;
        dfs(v, color==1?2:1);
    }
}

int main(){ _
    int n; cin >> n;
    ok=true;
    memset(c, 0,sizeof c);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int k; cin >> k;
            if (k) continue;
            g[i].pb(j);
            g[j].pb(i);
        }
    }
    dfs(1, 1);
    if (ok) cout << "Bazinga!" << endl;
    else cout << "Fail!"<<endl;
    exit(0);
}
