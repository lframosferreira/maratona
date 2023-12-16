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
  _
    int t; cin >> t;
  while (t--){
    int v, k;
    cin >> v >> k;
    vector<vector<pii>> g(v+1);
    priority_queue<pii, vector<pii>, Compare> pq;
    vector<bool> visited(v+1, false);
    while (k--){
      int a, b, c;
      cin >>a>>b>>c;
      g[a].pb({b, c});
    }
    int src, tgt;
    cin >> src >> tgt;
    pq.push({src, 0});
    int res  = -1;
    while (!pq.empty()){
      pii aux = pq.top();
      pq.pop();
      if (aux.f == tgt){
        res = aux.s;
        break;
      }
      for (auto neigh: g[aux.f]){
        pq.push({neigh.f, aux.s + neigh.s});
      }

    }

    if (res == -1){cout << "NO" << endl;}
        else {cout << res << endl;}
    }
        exit(0);
}
