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

class Compare{
    public:
        bool operator()(pair<pair<ll,ll>, ll> a, pair<pair<ll,ll>, ll> b){
            return a.f.s >= b.f.s;
        }
};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
vector<pair<pair<ll,ll>, ll>> g[MAX];

int main(){ 
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    int A, B;
    ll T, K;
    while(M--){
        cin >> A >> B >> T >> K;
        g[A].pb({{B, T}, K});
        g[B].pb({{A, T}, K});
    }
    vector<ll> dists(N+1, LINF);  
    priority_queue<pair<pair<ll,ll>, ll>, vector<pair<pair<ll,ll>, ll>>, Compare> pq;
    pq.push({{X, 0}, 1});
    ll ans = -1;
    while (!pq.empty()){
        auto aux = pq.top();
        pq.pop();
        dists[aux.f.f] = min(dists[aux.f.f], aux.f.s); 
        if (aux.f.f == Y){
            ans = aux.f.s;
            break;
        }
        for (auto neigh : g[aux.f.f]){
            if (dists[neigh.f.f] == LINF){
                int mod = aux.f.s % neigh.s;
                if (mod == 0) pq.push({{neigh.f.f, neigh.f.s + aux.f.s}, neigh.s});
                else pq.push({{neigh.f.f, neigh.f.s + aux.f.s + (neigh.s - aux.f.s%neigh.s)}, neigh.s});
           } 
        }
    }
    cout << ans << endl;
    exit(0);
}
