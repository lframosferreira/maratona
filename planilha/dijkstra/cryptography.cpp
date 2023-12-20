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

const int MAX = 130;
vector<pii> g[MAX];
bool calculated[MAX] = {false};
int dists[MAX][MAX];

class Compare{
    public:
        bool operator()(pii a, pii b){
            return a.s >= b.s;
        }

};

int main(){ 
    memset(dists, INF, sizeof(dists));
    string s, t;
    cin >> s >> t;
    int m; cin >> m;
    char u, v; int w;
    int src, tgt;
    while (m--){
        cin >> u >> v >> w; 
        src = int(u); 
        tgt = int(v);
        g[src].pb({tgt, w});
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++){
        src = int(s[i]);
        tgt = int(t[i]);
        if (calculated[src]){
            if (dists[src][tgt] == INF){
                ans = -1;
                cout << ans << endl;
                exit(0);
            }
            ans += dists[src][tgt]; 
        } else {
            calculated[src] = true;
            priority_queue<pii, vector<pii>, Compare> pq;
            pq.push({src, 0});
            while (!pq.empty()){
                pii aux = pq.top();
                pq.pop();
                dists[src][aux.f] = min(dists[src][aux.f], aux.s);
                for (auto neigh: g[aux.f]){
                    if (dists[src][neigh.f] == INF){
                        pq.push({neigh.f, aux.s + neigh.s});
                    }
                }
            } 
            if (dists[src][tgt] == INF){
                ans = -1;
                cout << ans << endl;
                exit(0);
            }
            ans += dists[src][tgt];
        }
    }
    cout << ans << endl;
    exit(0);
}
