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

class Compare{
    public:
        bool operator()(pii a, pii b){
            return a.s >= b.s;
        }
};

const int MAX = 1000+10;

int main(){ _
    int N, M, Q; 
    while(cin >> N >> M >> Q){
        vector<pii> g[MAX];
        int A, B, W;
        while (M--){
            cin >> A >> B >> W;
            g[A].pb({B, W});
            g[B].pb({A, W});
        }
        vector<int> hosp(Q);
        for (int i = 0; i < Q; i++){
            cin >> hosp[i];
            if (i!=0) g[hosp[0]].pb({hosp[i], 0});
        }
        int src = hosp[0];
        vector<int> dists(N+1, INF);
        priority_queue<pii, vector<pii>, Compare> pq;        
        pq.push({src, 0}); 
        while (!pq.empty()){
            pii aux = pq.top();
            pq.pop();
            dists[aux.f] = min(dists[aux.f], aux.s);
            for (auto neigh: g[aux.f]){
                if (dists[neigh.f] == INF){
                    pq.push({neigh.f, aux.s + neigh.s});
                }
            }
        }
        cout << *max_element(dists.begin()+1, dists.end()) << endl;
    }
    exit(0);
}
