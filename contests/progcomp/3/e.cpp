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

const int MAX = 110;

int dp[MAX][4];

int main(){ _
    memset(dp, -INF, sizeof dp); 
    int n; cin >> n;
    vi v(n); for (int &i: v) cin >> i;
    int mx=-INF;
    for (int j = 0; j <= 2; j++) {
        if (j==1){
            dp[0][j] = v[0] == 2 or v[0]==3;
        } else if (j==2){
            dp[0][j] = v[0]==1 or v[0]==3; 
        }
        else dp[0][j] = 0;
        mx=max(mx, dp[0][j]);
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 2; j++){
            if (j==0){
                dp[i][j]=max({dp[i-1][0],dp[i-1][1], dp[i-1][2]});
            }else if (j==1){
                if (v[i]==2 or v[i]==3){
                    dp[i][j] = max(dp[i-1][0], dp[i-1][2]) + 1;
                } else dp[i][j] = -INF;
                
            }else if (j == 2){
                if (v[i]==1 or v[i]==3){
                    dp[i][j] = max(dp[i-1][0], dp[i-1][1]) + 1;
                }else dp[i][j]=-INF;
            }
            mx=max(mx, dp[i][j]);
        }
    }

    cout << n - mx << endl; 
    exit(0);
}
