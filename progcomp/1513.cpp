// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 110;

int N, M, K;
char board[MAX][MAX];
bool vis[MAX][MAX];

void bfs(ii src){
    queue<ii> q;
    q.push(src);
    vis[src.f][src.s]=true;
    while (!q.empty()){
        
    }

}

int main(){ _
    while(true){
        cin >> N >> M >> K;
        if (n=0 and M==0 and K==0) break;
        for (int i = 0; i < N; i++){
            string aux; cin >> aux;
            for (int j = 0; j < M; j++){
                board[i][j]=aux[j];
            }
        } 
    } 
    exit(0);
}
