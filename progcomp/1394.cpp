// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 45;

struct Edge{
    int to;int w; int rev_idx;
};

int N, M, G;
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

int games[MAX][MAX];
int pnts[MAX];

void setup(){
    memset(pnts, 0, sizeof pnts);
    memset(games, 0, sizeof games);
    g.clear();g.resize(N+1);
    for (int i = 0; i < N; i++){
        for (int j=i+1; j < N; j++){
            games[i][j]+=M;
        }
    }
}

int main(){ _
    while (1){
        cin >>N >> M >> G;
        if(N==0) break;
        setup();
        while (G--){
            char r; int i, j;
            cin >> i >>r>> j;
            if (r=='<'){
                pnts[j]+=2;
            } else {
                pnts[i]++;pnts[j]++;
            }
        }
    } 
    exit(0);
}
