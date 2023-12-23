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

const int MAX = 2 * 1e5 + 10;
vector<int> g[MAX];
bool visited[MAX];

void dfs(int u){
	if (vis[u]) return;
	for (auto v: g[u]){
		dfs(v);
	}
}

int main(){ _
    memset(visited, false, sizeof(visited));
    int n, m;
    while (m--){
	int u, v; cin >> u >> v;
	g[u].pb(v);
	g[v].pb(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
	if (vis[i]) continue;
	dfs(i);
	ans++;
    }

    exit(0);
}
