// pescoço pra baixo é canela
// NAO ENVIAR ASSIM

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

int main(){ _
    while (1){
        int R, C, K; cin >> R >> C >> K;
        if (R==0 and C==0 and K==0) break;
        vector<string> v(R+1);
        for (int i = 1; i <= R; i++){
            string aux; cin >> aux;
            v[i]="X"+aux;
        }
        vector<vector<int>> dp(R+1, vector<int>(C+1));
        for (int i = 1; i <= R; i++){
            for (int j = 1; j <= C; j++){
                if (v[i][j]=='.'){
                    dp[i][j]=1;
                }else dp[i][j]=0;
                if (i>1){
                    dp[i][j]+=dp[i-1][j];
                }
                if (j > 1){
                    dp[i][j]+=dp[i][j-1];
                }
                if (i>1 and j > 1){
                    dp[i][j]-=dp[i-1][j-1];
                }
            } 
        }
        int ans=INT_MAX; 
        for (int i = 1; i <= C; i++){
            for (int j = 1; j <= C; j++){
                int p=1;
                for (int w=1; w <= R; w++){
                    while (dp[w][j] - dp[w][i-1] - dp[p-1][j] + dp[p-1][i-1] >= K){
                        ans=min(ans, (w-p+1)*(j-i+1));
                        p++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    exit(0);
}
