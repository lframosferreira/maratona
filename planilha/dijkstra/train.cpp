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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;

vector<pair<pll, ll>> g[MAX];

int main(){ _ 
    int N, M, X, Y; 
    cin >> N >> M >> X >> Y;
    int A, B;
    ll T, K;
    while(M--){
        cin >> A >> B >> T >> K;
        g[A].pb({{T, B}, K});
        g[B].pb({{T, A}, K});
    }
    vector<ll> dists(N+1, LINF);  
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, X);
    ll ans = -1;
    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if (w > dists[u]) continue;
        dists[u] = w; 
        if (u == Y){
            ans = dists[u];
            break;
        }
        for (auto [aux, wait]: g[u]){
            auto [v_w, v] = aux;
            if (dists[v] == LINF){
                int mod = w % wait;
                if (mod == 0) pq.emplace(v_w + w, v);
                else pq.emplace(v_w + w + wait - mod, v);
           } 
        }
    }
    cout << ans << endl;
    exit(0);
}
