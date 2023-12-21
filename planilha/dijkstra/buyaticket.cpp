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

vector<pair<ll, int>> g[MAX];
//IDEIA
//COLOCAR PESOS DOBRADOS PRA JA CONTABILIZAR VOLTA
int main(){ _ 
    int n, m; cin >> n >> m;
    vector<ll> a(n+1);
    vector<ll> costs(n+1, LINF);
    int vi, ui;
    ll wi;
    while (m--){
       cin >> vi >> ui >> wi;
       g[vi].pb({wi, ui}); 
       g[ui].pb({wi, vi}); 
    } 
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        vector<ll> dists(n+1, LINF);
        vector<bool> vis(n+1, false);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(0, i);
        while (!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            costs[i] = min(costs[i], 2*w + a[u]);
            vis[u] = true;
            for (auto [v_w, v]: g[u]){
                if (w+v_w <= dists[v]) {
                    dists[v] = v_w + w;
                    if(!vis[v]){
                        pq.emplace(v_w + w, v);
                    }
                }
            }
        }
    } 

    for (int i = 1; i <= n; i++){
        cout << costs[i] << " ";
    }
    cout << endl;
    exit(0);
}
