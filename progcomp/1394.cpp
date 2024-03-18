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

int main(){ _
    while (1){
        int N, M, G; cin >>N >> M >> G;
        if(N==0) break;
        vector<vector<int>> g(N, vector<int>(N, M*2)); 
        vector<int> pnts(N);
        while (G--){
            char r; int i, j;
            cin >> i >>r>> j;
            if (r=='<'){
                pnts[j]+=2;
                g[j][i]-=2;
                g[i][j]-=2;
            } else {
                pnts[i]++;pnts[j]++;
                g[j][i]-=2;
                g[i][j]-=2;
            }
        }
        for (int i = 1;i <N;i++){
            pnts[0]+=g[0][i];
            g[i][0]=0;
        }
        for (int i = 1;i < N; i++){
            int maybe=pnts[i];
            for (int j = 1;j < N;j++){
                if(i==j) continue;
                maybe+=g[i][j]; 
            }
            if (maybe >= pnts[0]){
                can=false;break;
            }
        }
        if(can) cout << "Y" <<endl;
        else cout << "N" << endl;
    } 
    exit(0);
}
