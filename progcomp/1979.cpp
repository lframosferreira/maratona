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
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
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

int colors[110];
bool bad;
vvi g;

void dfs(int u, int color){
    if (colors[u]) return;
    colors[u]= color;
    for (auto v: g[u]){
        if (colors[v] and colors[v] == color) {
            bad=true;
        }
        else if (colors[v]) continue;
        dfs(v, (color == 1 ? 2 : 1));
    }
}

int main(){ _
    int N;
    while (1){
        cin >> N;if (N==0) break;
        g.clear();
        g.resize(N+1);
        for (int i = 1;i <=N;i++){
            int lixo;cin >> lixo;
            cin.ignore();
            string line; getline(cin, line);
            stringstream ss(line);
            int a;
            while (ss >> a){
                g[i].pb(a);
                g[a].pb(i);
            }
        }
        memset(colors, 0, sizeof colors);
        colors[1]=0;
        bad=false;
        dfs(1, 1);
        cout << (bad ? "NAO": "SIM") << endl;
    }
    exit(0);
}
