#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Compare{
    public:
        bool operator()(pii a, pii b){
            return a.s >= b.s;
        }

};

int main(){ 
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pii>> g(n+1);
    vector<int> friends(n+1);
    vector<int> dtof(n+1, INF);
    vector<int> stof(n+1, INF);
    while (m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    while (x--){
        int f; cin >> f;
        friends[f] = 1;
    }

    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({1, 0});
    while (!pq.empty()){
        pii aux = pq.top();
        pq.pop();
        dtof[aux.f] = min(aux.s, dtof[aux.f]);
        for (auto neigh: g[aux.f]){
            if (dtof[neigh.f] == INF){
                pq.push({neigh.f, aux.s + neigh.s});
            }
        }
    }

    // hope pq is empty
    pq.push({n, 0});
    while (!pq.empty()){
        pii aux = pq.top();
        pq.pop();
        stof[aux.f] = min(aux.s, stof[aux.f]);
        for (auto neigh: g[aux.f]){
            if (stof[neigh.f] == INF){
                pq.push({neigh.f, aux.s + neigh.s});
            }
        }
    }
    int c = INF;
    for (int i = 1; i <= n; i++){
        if (friends[i] == 1){ 
            c = min(c, dtof[i]+stof[i]);
        }
    }
    cout << c << endl;


        exit(0);
}
