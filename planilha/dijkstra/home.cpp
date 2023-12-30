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


int main(){ _
    ll n;int  m; cin >> n >> m;        
    vector<pair<ll, ll>> nodes(m+2);
    vector<vector<pair<ll ,ll>> g(m+2);
    ll sx, sy, fx, fy; cin >> sx >> sy >> fx >> fy;
    nodes[0] = {sx, sy};
    nodes[m+1] = {fx, fy};
    for (int i = 1; i <= m; i++){
        ll a, b;
        cin >> a >> b;
        nodes[i] = {a, b};
    }
    sort(nodes.begin(), nodes.end());
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll ,int>>> pq;
    vector<ll> dists(m+2, LINF);
    vector<bool> vis(m+2, false);
    pq.emplace(0, 0); 
    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        vis[u] = true;
        if (w > dists[u]) continue;
        if (u == m+1){
            break;
        }
        for (int v = 0; v <= m+1; v++){
            if (u == v || vis[v]) continue;
            ll v_w = -1;
            if (v==m+1){
                v_w = abs(nodes[u].f - nodes[v].f) + abs(nodes[u].s - nodes[v].s); 
            } else {
                v_w = min(abs(nodes[u].f - nodes[v].f), abs(nodes[u].s - nodes[v].s)); 
            }
            if (dists[v] > w + v_w){
                dists[v] = w + v_w;
                pq.emplace(w+v_w, v);
            }
        }
    }
    cout << dists[m+1] << endl; 
    exit(0);
}
