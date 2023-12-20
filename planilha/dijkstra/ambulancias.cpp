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
vector<pii> g[MAX];

int main(){
    int N, M, Q; 
    vector<int> global_dists(N+1, INF);
    cin >> N >> M >> Q;
    int A, B, W;
    while (M--){
        cin >> A >> B >> W;
        g[A].pb({B, W});
        g[B].pb({A, W});
    }
    vector<int> hosp(Q);
    for (int &h: hosp) cin >> h;
    for (int &h: hosp){
        vector<int> dists(N+1, INF);
        priority_queue<pii, vector<pii>, Compare> pq;        
        pq.push({h, 0}); 
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
        for (int i = 0; i < N; i++) global_dists[i] = min(global_dists[i], dists[i]);
    }
    cout << *max_element(global_dists.begin(), global_dists.end()) << endl;

    exit(0);
}
