// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N;

int main(){ _
    while (1){
        cin >> N; if (N==0) break;
        vector<iii> pts(N+1);
        vector<vector<pair<int, double>>> g(N+1);
        for (int i = 1; i <= N; i++){
            auto &[x, y, r] = pts[i];
            cin >> x >> y >> r;
        }
        vvd dists(N+1, vd(N+1, numeric_limits<double>::max()));
        for (int i = 1; i <= N; i++){
            for (int j = i+1; j <=N; j++){
                auto &[x1,y1,r1]=pts[i];
                auto &[x2,y2,r2]=pts[j];
                double d = sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2));
                if ((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2) <= r1*r1){
                    g[i].pb({j, d});
                }
                if ((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2) <= r2*r2){
                    g[j].pb({i, d});
                }
            }
        }
        int C; cin >> C;
        vi calc(N+1);
        while (C--){
            int A1, A2; cin >> A1 >> A2;
            if (!calc[A1]){
                int i=A1;

                priority_queue<pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>>> pq;
                pq.push({i, 0});
                dists[i][i]=0;
                while (sz(pq)){
                    auto [u, w] = pq.top();pq.pop();
                    if (w > dists[i][u]) continue;
                    for (auto [v, wv]: g[u]){
                        if (dists[i][v] > w+wv) {
                            dists[i][v] = w+wv;
                            pq.push({v, w+wv}); 
                        }
                    }
                }
            }
            cout << floor(dists[A1][A2] > 300000.0 ? -1 : dists[A1][A2]) << endl;
        }
    } 
    exit(0);
}
