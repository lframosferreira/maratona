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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char v[1010][1010];

int h, w;
set<pii> black;

vector<pii> moves = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

struct aux{
    int i;int j; int d;
};

int dists[1010][1010];

bool ok(int i, int j){
    return i >= 0 and i < h and j >= 0 and j < w;
}

int main(){
    cin >> h >> w;
    memset(dists, INF, sizeof dists);
    int ans=-INF;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> v[i][j];
            if (v[i][j]=='#') black.insert({i, j});
        }
    }
    queue<aux> q;
    for (auto [a, b]: black){
        q.push({a, b, 0});
    }
    while (!q.empty()){
        auto curr = q.front();q.pop();
        if (dists[curr.i][curr.j]!=INF) continue;
        dists[curr.i][curr.j]=curr.d;
        ans=max(ans, curr.d);
        for (auto [x, y]: moves){
           if(ok(curr.i+x, curr.j+y) and dists[curr.i+x][curr.j+y] == INF) q.push({curr.i+x, curr.j+y, curr.d+1}); 
        }
    }
    cout << ans << endl;
    exit(0);
}

