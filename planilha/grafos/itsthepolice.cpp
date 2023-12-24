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

const int MAX= 2e5 + 10;
vector<int> g[MAX];
int dg[MAX];

int main(){ _
	memset(dg, 0, sizeof(dg));
	int n, m; cin >>n >> m;
	vector<int> ans(n+1, 1);
	while(m--){
		int u,v;
		cin >> u >>v;
		g[u].pb(v);
		g[v].pb(u);
		dg[u]++;
		dg[v]++;
	}
	int idx = 1;
	for (int i = 2;i<=n; i++){
		if (dg[i]<dg[idx]) idx= i;
	} 
	ans[idx] = 0;
	for (auto nei: g[idx]) ans[nei] = 0;
	for (int i = 1; i<= n; i++) cout << ans[i] << " ";
	cout << endl;
    exit(0);
}
