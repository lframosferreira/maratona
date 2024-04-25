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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, M, A;

const int MAX = 60;

struct Edge {
    int to;
    int w;
    int rev_idx;
};

int src, tgt;
pii par[MAX];
int gargalo;
bool vis[MAX];
vector<vector<Edge>> g;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while (!q.empty()){
        auto v=q.front();q.pop();
        for (int i = 0; i < g[v].size(); i++){
            auto edg=g[v][i];
            if (edg.w <=0) continue;
            if (vis[edg.to]) continue;
            vis[edg.to]=true;
            if (edg.to==tgt){
                par[edg.to]={v, i};
                return true;
            }
            par[edg.to]={v, i};
            q.push(edg.to);
        }
    }
    return false;
}

int main(){ _
    while (true){
        cin >> N >> M >> A; 
        if (N == M == A == 0) break;
        while (M--){
            int O, D, S;
            cin >> O >> D >> S;
            g[O].pb({D, S, g[D].size()});
            g[D].pb({O, 0, g[O].size()-1});

            g[D].pb({O, S, g[O].size()});
            g[O].pb({D, 0, g[D].size()-1});
        }
        

        
    }
    cout << endl;
    exit(0);
}
