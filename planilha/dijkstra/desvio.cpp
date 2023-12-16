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


int main(){ _
    
    while (true){
      vector<pii> g[250];
      int N, M, C, K;
      cin >> N >> M >> C >> K;
      if (N == 0 && M == 0 && C == 0 && K == 0) break;
      int total = 0;
      vector<int> mainpath(N, INF);
      while (M--){
        int U, V, P;
        cin >>U >>V >>P;
        g[U].pb({V, P});
        g[V].pb({U, P});
        if (V - U == 1) mainpath[U] = P;
        if (U - V == 1) mainpath[V] = P;
      }
      priority_queue<pii, vector<pii>, Compare> pq;
      vector<int> dists(N, INF); 
      pq.push({K, 0}); 
      while (!pq.empty()){ 
        pii aux = pq.top();
        pq.pop();
        dists[aux.f] = min(dists[aux.f], aux.s);
        if (aux.f > C - 1){
          for (auto neigh: g[aux.f]){
            if (dists[neigh.f] == INF){
              pq.push({neigh.f, aux.s + neigh.s});
            }
          }
        } else {
          if (dists[aux.f + 1] == INF){
            if (mainpath[aux.f] != INF){
              pq.push({aux.f + 1, aux.s + mainpath[aux.f]});
            }
          }
        }
      }
      cout << dists[C-1] << endl;
    }
    exit(0);
}
