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

int main(){ _
    int N, M; cin >> N >> M;
    vector<vector<pii>> g(N+1);
    vi d(N+1, INF);
    vi vis(N+1);
    int U, V, P;
    while (M--){
        cin >> U >> V >> P;
        g[U].pb({P, V});
        g[V].pb({P, U});
    }
    int S; cin >> S;
    d[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, S);
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        d[u] = w;
        for (auto [w_v, v]: g[u]){
           if (!vis[v]) pq.emplace(w+w_v, v); 
        } 
    }
    int mn = INF;
    int mx = -INF;
    for (int i = 1; i <= N; i++){
        if (i==S) continue;
        if (d[i] < mn) mn = d[i];
        if (d[i] > mx) mx = d[i];
    }
    cout << mx-mn << endl;
    exit(0);
}
