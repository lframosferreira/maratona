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

const int MAX = 1000+10;

int main(){ _
    int N, M, Q; 
    while(cin >> N >> M >> Q){
        vector<pii> g[MAX];
        int A, B, W;
        while (M--){
            cin >> A >> B >> W;
            g[A].pb({W, B});
            g[B].pb({W, A});
        }
        int ans = -INF;
        vector<int> hosp(Q);
        for (int i = 0; i < Q; i++){
            cin >> hosp[i];
            if (i!=0) g[hosp[0]].pb({0, hosp[i]});
        }
        int src = hosp[0];
        vector<int> dists(N+1, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;        
        pq.emplace(0, src); 
        int ok = 0;
        while (!pq.empty()){
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dists[u]) continue;
            dists[u] = w;
            ans=max(ans, w);
            ok++;
            for (auto [v_w, v]: g[u]){
                if (dists[v] > w+v_w){
                    pq.emplace(w + v_w, v);
                }
            }
        }
        cout << ans << endl;
    }
    exit(0);
}
