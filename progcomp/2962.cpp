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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e3 + 10;

vector<bool> r;
vector<bool> l;
bool vis[MAX];
vector<vector<int>> g;
bool pode;

void dfs(int u){
    if (vis[u]) return;
    vis[u]=1;
    if (r[u]) pode = false;
    for (auto v: g[u]) dfs(v);
}

int main(){ _
    int M, N, K; cin >> M >> N >> K;
    vector<tuple<int, int, int>> sensors(K);
    r.resize(K, false);
    l.resize(K, false);
    for (int i = 0; i < K; i++){
        int X, Y, S; cin >> X >> Y >> S;
        sensors[i] = {X, Y, S};
        if (X + S >= M or Y - S <= 0) r[i]=true;
        if (X - S <= 0 or Y + S >= N) l[i]=true;
        if (r[i] and l[i]) {
            cout << "N" << endl;
            exit(0);
        }
    }
    g.resize(K);
    for (int i = 0; i < K; i++){
        for (int j = i+1; j < K; j++){
            auto [x1, y1, s1] = sensors[i];
            auto [x2, y2, s2] = sensors[j];
            if (s1+s2 >= sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))){
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    pode = true;
    for (int i = 0; i < K; i++){
        memset(vis, false, sizeof vis);
        if (l[i]) dfs(i);
        if (!pode) break;
    }
    if (pode) cout << "S" << endl;
    else cout << "N" << endl;
    exit(0);
}
