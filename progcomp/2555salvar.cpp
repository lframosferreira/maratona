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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, K;

void printdp(vector<vector<double>> &v){
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
        vector<vector<double>> dp1(N+1, vector<double>(K+1));
        vector<vector<double>> acumulada1(N+1, vector<double>(K+1, 1.0));
        for (int i = 1; i <= N; i++) {
            dp1[i][0] += dp1[i-1][0] + premios[i] * (acumulada1[i-1][0] * ((double)chance[i] / 100.0));
            acumulada1[i][0] =  ((double)chance[i] / 100.0) *acumulada1[i-1][0];
        }
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= K; j++){
                double x = dp1[i-1][j] + (double)premios[i]*(acumulada1[i-1][j]*((double)chance[i] / 100.0));
                double y = dp1[i-1][j-1] + (double)premios[i] * acumulada1[i-1][j-1];
                if (x >= y){
                    dp1[i][j] = x;
                    acumulada1[i][j] = ((double)chance[i] / 100.0) *acumulada1[i-1][j];
                }else {
                    dp1[i][j]=y;
                    acumulada1[i][j] = acumulada1[i-1][j-1];
                }
            }
        }
        printdp(dp1);
    }
    exit(0);
}
