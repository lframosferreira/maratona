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
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 210;
int v[MAX][MAX];

vector<pii> moves = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
int N, M;

bool oob(int x, int y){
    return x < 0 or x >= N or y < 0 or y >= M;
}

int ans;

void dfs(int x, int y, int prof){
    ans=max(ans, prof);
    for (auto move: moves){
        if (!oob(x+move.f, y+move.s) and v[x+move.f][y+move.s]==2 and !oob(x+2*move.f, y+2*move.s) and v[x+2*move.f][y+2*move.s]==0){
            v[x+move.f][y+move.s]=0;
            v[x][y]=0;
            v[x+2*move.f][y+2*move.s]=1;
            dfs(x+2*move.f, y+2*move.s, prof+1);
            v[x][y]=1;
            v[x+2*move.f][y+2*move.s]=0;
            v[x+move.f][y+move.s]=2;
        }
    } 
}

int main(){ _
    while (1){
        memset(v, 0, sizeof v);
        ans=-INF;
        cin >> N >> M;
        if (N == 0 and M == 0) break;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (i%2==0){
                    if (j%2==0) {
                        cin >> v[N-1-i][j];
                    }
                } else {
                    if (j%2==1){
                        cin >> v[N-1-i][j];    
                    }
                }
            }
        } 
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (v[i][j]==1){
                    dfs(i, j, 0);
                }
            }
        } 
        cout << max(0, ans) << endl;
    } 
    exit(0);
}
