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

int main(){ 
    cout << fixed << setprecision(4);
    int N, K;
    long double V;
    while (cin >> N >> K >> V){
        vector<long double> monster_hp(N+1);
        vector<long double> dmg_increase(N+1);
        for (int i = 1; i <= N; i++) cin >> monster_hp[i] >> dmg_increase[i];
        vector<vector<long double>> dp(N + 1, vector<long double>(K + 1, numeric_limits<long double>::max()));

        // matar monstro '0' toma 0 de tempo
        for (int i = 0; i <= K; i++) dp[0][i]=0;

        // matar monstro i com 0 de mana é tempo ate anterior mais hp/danopadrao
        dp[1][0] = monster_hp[1] / V;
        for (int i = 2; i <= N; i++) dp[i][0] = (monster_hp[i] / V) + dp[i-1][0];


        for (int i = 1; i <= N; i++){
            for (int j = 0; j <= K; j++){
                for (int q = 0; q <= j; q++){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-q] + monster_hp[i]/(V+q*dmg_increase[i]));
                }
            }
        }
        cout << dp[N][K] << endl;
    }
    exit(0);
}
