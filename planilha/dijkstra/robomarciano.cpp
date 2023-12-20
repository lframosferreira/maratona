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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const inx MAX = 1000+10;

int g[MAX][MAX];
int mapa[MAX][MAX];

int main(){ _
    memset(g, 1, sizeof(g));
    memset(mapa, 0, sizeof(mapa));
    int xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;
    int n; cin >> n;    
    int x1, y1, x2, y2;
    int id = 1;
    while (n--){
         cin >> x1 >> y1 >> x2 >> y2;
         for (int i = min(x1, x2); x <= max(x1, x2); i++)
               for (int j = min(y1, y2); j <= max(y1, y2); j++)
                   mapa[i][j] = id;
         id++;
    }   
    exit(0);
}
