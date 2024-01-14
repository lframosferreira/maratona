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

const int MAX = 2e5 + 10;

bool vis[MAX];
set<int> g[MAX];
int cnt, ki, ans;

void dfs(int u){
    if (cnt == ki) return;
    if (vis[u]) return;
    vis[u] = true;
    cnt++;
    if (cnt == ki) {
        ans=u;
        return;
    };
    for (auto v: g[u]){
        dfs(v);
    }
}

int main(){ _
    int n, q;
    cin >> n >> q;
    int u;
    for (int i = 2; i <= n; i++){
        cin >> u;
        g[u].insert(i);
    }
    int ui;
    while (q--){
        cin >> ui >> ki;
        memset(vis, false, sizeof vis);
        cnt=0;
        ans=-1;
        dfs(ui);
        cout << ans << endl;
    }

    exit(0);
}
