// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n, m; cin >> n >> m;
    vector<ll> c(n+1);
    for (int i = 1; i <= n; i++) cin >> c[i]; 
    map<pii, ll> rel;
    while (m--){
        ll i, j, r; cin >> i >> j >> r;
        pii aux = {i, j};
        pii aux2 = {j, i};
        rel[aux] = r;
        rel[aux2] = r;
    }
    ll ans = 0;
    vector<bool> vis(n+1, false);
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
    pq.push({1, 0});
    while (!pq.empty()){
        auto [u, w] = pq.top();pq.pop();
        if (vis[u]) continue;
        vis[u]=true;
        ans+=w;
        for (int v = 1; v <= n; v++){
            if (u==v) continue;
            pii aux = {u, v};
            ll val = rel.find(aux) == rel.end() ? LINF : rel[aux];
            if (!vis[v]) pq.push({v, min(c[u]+c[v], val)});
        }
    }
    cout << ans << endl;
    exit(0);
}
