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

struct Edge{
    int to;int w; int rev_idx;
};

vector<vector<Edge>> g;
int games[MAX][MAX];
int pnts[MAX];

int main(){ _
    while (1){
        int N, M, G; cin >>N >> M >> G;
        if(N==0) break;
        memset(pnts, 0, sizeof pnts);
        memset(games, 0, sizeof games);
        g.clear();g.resize(N+1);
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
