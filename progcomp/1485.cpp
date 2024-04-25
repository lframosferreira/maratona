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
typedef vector<vd> vdd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int S, B;

int main(){ _
    while (1){
        cin >> S >> B;
        if (S==0 and B==0) break; 
        vi roleta(S); for (int &i: roleta) cin >> i;
        vi bolas(B);for (int &i: bolas) cin >> i;
        vvi dp(S, vi(B));
        int ans=INF;
        for (int i = 0; i < S; i++){
            for (int j = 0; j < B; j++){
                for (int k = 0; k < i; k++){
                    dp[i][j]=min(dp[i-1][j], bolas[j]*(roleta[i%S]+roleta[(i+1)%S]));
                }
            }
            ans=min(ans, dp[S-1][B-1]);
        }
        cout << ans << endl;
    }    
    exit(0);
}
