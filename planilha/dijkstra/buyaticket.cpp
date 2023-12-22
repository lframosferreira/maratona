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

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<ll> a(n+1);
    int vi, ui;
    ll wi;
    while (m--){
       cin >> vi >> ui >> wi;
       g[vi].pb({2*wi, ui}); 
       g[ui].pb({2*wi, vi}); 
    } 
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        g[0].pb({a[i], i});
        g[i].pb({a[i], 0});
    }
    vector<ll> dists(n+1, LINF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if (w>dists[u]) continue;
        for (auto [v_w, v]: g[u]){
            if (dists[v] > w+v_w) {
                dists[v] = v_w + w;
                pq.emplace(v_w + w, v);
            }
        }
    } 

    for (int i = 1; i <= n; i++){
        cout << dists[i] << " ";
    }
    cout << endl;
    exit(0);
}
