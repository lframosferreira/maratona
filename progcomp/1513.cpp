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

int oob(int x, int y){
    return x < 0 or x >= N or y < 0 or y >= M;
}

vector<ii> moves = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

int dp[105][105][18];
char board[105][105];
vector<ii> p;
int g[21][21];

int main(){ _
    while (1){
        cin >> N >> M >> K;
        if (N==0 and M==0 and K==0) break;
        p.clear();
        memset(dp, INF, sizeof dp);
        memset(board, 0, sizeof board);
        string str;
        ii h_pos;
        for (int i = 0; i < N; i++){
            cin >> str;
            for (int j = 0; j < sz(str); j++){
                if (str[j]=='C') h_pos=mp(i, j);
                if (str[j]=='P') p.pb(mp(i,j));
                cin >> board[i][j];
            }
        }
        dp[h_pos.f][h_pos.s][0]=0;
        // usar bfs
        queue<ii> q;
        q.push(h_pos);
        while (sz(q)){
            auto [x, y] = q.front();q.pop();
            // condicao de parada

            for (auto [a, b] : moves){
                if (oob(x+a, y+b) or board[x+a][y+b]=='#') continue;

                       
            }
        }

    } 
    exit(0);
}
