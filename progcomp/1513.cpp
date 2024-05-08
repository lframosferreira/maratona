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

int N, M, K;
int dp[21][1 << 17];
char board[105][105];
int g[21][21];
map<ii, int> peoes_idx;
ii peoes_coo[21];

int oob(int x, int y){
    return x < 0 or x >= N or y < 0 or y >= M;
}

vector<ii> moves = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

int main(){
    while (1){
        cin >> N >> M >> K;
        if (N==0 and M==0 and K==0) break;
        memset(dp, INF, sizeof dp);
        memset(board, 0, sizeof board);
        memset(g, INF, sizeof g);
        string str;
        ii h_pos;
        int cnt_peoes=0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M;j++){
                cin >> board[i][j];
                if (board[i][j]=='C') h_pos=mp(i, j);
                if (board[i][j]=='P') {
                    peoes_idx[mp(i,j)]=cnt_peoes;
                    peoes_coo[cnt_peoes]=mp(i,j);
                    cnt_peoes++;
                }
            }
        }
        // usar bfs para construir grafo a partir de todo peao p achar menores caminhos
        for (int p = 0; p < cnt_peoes; p++){
            queue<pair<ii, int>> q;
            q.push({peoes_coo[p], 0});
            while (sz(q)){
                auto [coo, d] = q.front();q.pop();
                auto [x, y] = coo;
                // condicao de parada
                if (board[x][y]=='P') {
                    int peao_x=peoes_coo[peoes_idx[mp(x, y)]].f;
                    int peao_y=peoes_coo[peoes_idx[mp(x, y)]].s;
                    if (g[peao_x][peao_y]!=INF) continue;
                    g[peao_x][peao_y]=d;
                }
                for (auto [a, b] : moves){
                    if (oob(x+a, y+b) or board[x+a][y+b]=='#') continue;
                    q.push({mp(x+a, y+b), d+1});
                }
            }
        }
        for (int i = 0; i <cnt_peoes;i++){
            for (int j = 0;j < cnt_peoes;j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    } 
    exit(0);
}
