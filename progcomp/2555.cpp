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
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, K;

void printdp(vvd &v){
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= K; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }    
    cout << "-----"<< endl;
}

int main(){ _
    cout << fixed << setprecision(2);
    while (cin >> N >> K){
        vi premios(N+1);
        for (int i = 1; i <= N; i++) cin >> premios[i];
        vi chance(N+1);
        for (int i = 1; i <= N; i++) cin >> chance[i];
        vvd dp(N+1, vd(K+1));
        vvd acumulada(N+1, vd(K+1));
        for (int i = 0; i <= K; i++){
            dp[N][i] = i > 0 ? (double)premios[N] : (double)premios[N]*((double)chance[N]/100.0);
            acumulada[N][i] = i > 0 ? 1.0 : (double)chance[N]/100.0;
        }
        for (int i = N-1; i >= 0; i--){
            for (int j = K-1; j >= 0; j--){
                double x = dp[i+1][j] + (double)premios[i]*acumulada[i+1][j];
                double y = ((double) chance[i]/100.0)*dp[i+1][j+1]+ (double)premios[i]*((double)chance[i]/100.0)*acumulada[i+1][j+1];
                if (y >= x){
                    dp[i][j] = y;
                    acumulada[i][j] = ((double)chance[i] / 100.0) *acumulada[i+1][j+1];
                }else {
                    dp[i][j]=x;
                    acumulada[i][j] = acumulada[i+1][j];
                }
            }
        }
        printdp(dp);
        
        printdp(acumulada);
    }
    exit(0);
}
