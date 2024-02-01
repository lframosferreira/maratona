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
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    cout << fixed << setprecision(3);
    int N, M, K;
    double P;
    while (cin >> N >> M >> K >> P){
        vector<vector<pii>> g(N + 1);
        while (M--){
            int i, j; cin >> i >> j;
            g[i].pb({j, 0.0});
            g[j].pb({i, 0.0});
        }
        int A; cin >> A;
        vi city(N + 1);
        while (A--){
            int pos; cin >> pos;
            city[pos] += 1;
        }
        for (int i = 1; i <= N; i++){
            for (int j = 0; j < g[i].size(); j++){
                if (city[g[i][j].f]) g[i][j].s += city[g[i][j].f]; 
            }
        }
        int start, finish; cin >> start >> finish;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dists(N+1, INF);
        dists[start] = 0; 
        pq.emplace(0, start);
        while (!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dists[u]) continue;
            for (auto [v, w_v]: g[u]){
                if (dists[v] > dists[u] + w_v){
                    dists[v] = dists[u] + w_v;
                    pq.emplace(dists[v], v); 
                }
            }
        }
        double ans = 1.0;
        if (dists[finish] > K - city[start]) ans = 0;
        else {
            for (int i = 0; i < dists[finish] + city[start]; i++) ans *= P;
        }
        cout << ans << endl;
    }
    exit(0);
}
