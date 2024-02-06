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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll; 
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dp[110][60];
int pesos[110][60];
int usados[110][60];

int main(){ _
    int n; cin >> n;
    while (n--){
        memset(dp, 0, sizeof dp);
        memset(pesos, 0, sizeof pesos);
        memset(usados, 0, sizeof usados);
        int pac; cin >> pac;
        vi v(pac+1), w(pac+1);
        int a, b;
        for (int i = 0; i < pac; i++){
            cin >> a >> b;
            w[i] = b;
            v[i] = a;
        }
        for (int i = 1; i <= pac; i++){
            for (int j = 1; j <= 50; j++){
                dp[i][j] = dp[i-1][j];
                pesos[i][j] = pesos[i-1][j];
                usados[i][j] = usados[i-1][j];
                if (w[i-1] <= j){
                    int pos = dp[i-1][j - w[i-1]] + v[i-1];
                    if (dp[i][j] < pos) {
                        dp[i][j] = pos;
                        pesos[i][j] = pesos[i-1][j-w[i-1]] + w[i-1];
                        usados[i][j] = usados[i-1][j-w[i-1]] + 1;
                    }
                }
            }
        }
        cout << dp[pac][50] << " brinquedos" << endl;
        cout << "Peso: " << pesos[pac][50] << " kg" << endl;
        cout << "sobra(m) " << pac-usados[pac][50] << " pacote(s)" << endl;
        cout << endl;
    }
    exit(0);
}
