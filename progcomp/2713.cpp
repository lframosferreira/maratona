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
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    cout << fixed << setprecision(5);
    int N, K, V;
    while (cin >> N >> K >> V){
        vector<int> damage(N+1);
        vector<int> monster(N+1);
        for (int i = 1; i <= N; i++){
            cin >> monster[i] >> damage[i];
        }
        vector<vector<double>> dp(N+1, vector<double>(K+1));
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= K; j++){
                int spent_mana = max(min(monster[i]-V, j), 0);
                double aux = (double)monster[i] / (double)(V + spent_mana*damage[i]);
                dp[i][j]= dp[i-1][j] + min((double)monster[i]/(double)V, aux);
            }
        }
        cout << dp[N][K] << endl;
    }
    exit(0);
}
