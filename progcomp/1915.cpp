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
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, M;
const int MAX = 210;

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

int dp[110][110];

int dist(vi &a, vi &b){
    memset(dp, 0, sizeof dp); 
    for (int i = a.size()-1; i>=0; i--){
        for (int j = b.size()-1; j >= 0; j--){
            if (a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            } else {
                dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return a.size() + b.size() - 2*dp[0][0];
}

int cnt[27];

int main(){ _
    while (1){
        cin >> N >> M;
        if (N==0 and M ==0) break; 
        g.clear();g.resize(N+M+2);
        vvi nomes(N+1);
        vvi brinquedos(M+1); 
        for (int i = 1; i <= N; i++){
            string nome; cin >> nome;
            memset(cnt, 0, sizeof cnt);
            vi v(nome.size()); 
            for (int j = 0; j < nome.size(); j++){
                v[j]=(nome[j]-'A')+1 + 26*cnt[(nome[j]-'A')+1]; 
                cnt[(nome[j]-'A')+1]++;
            }
            nomes[i]=v;
        }

        for (int i = 1; i <= M; i++){
            string brinq; cin >> brinq;
            memset(cnt, 0, sizeof cnt);
            vi v(brinq.size()); 
            for (int j = 0; j < brinq.size(); j++){
                v[j]=(brinq[j]-'A')+1 + 26*cnt[(brinq[j]-'A')+1]; 
                cnt[(brinq[j]-'A')+1]++;
            }
            brinquedos[i]=v;
        }
        
        // cria grafo
        for (int i = 1; i <= N; i++){
            for (int j = i+1; j <= M; j++){
                if (dist(nomes[i], brinquedos[j])%5==0){
                    g[i].pb({j, 1, g[j].size()});
                    g[j].pb({i, 0, g[i].size()-1});
                }
            }
        }

        // criar arestas da src

        // criar arestas do tgt
        

        // roda edmond karp

    } 
    exit(0);
}
