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

const int MAX = 1e5+10;
int dp[MAX][4];
int a[MAX], b[MAX], c[MAX];

// a=0 b=1 c=2
int main(){ _
    int n; cin >> n;
    memset(dp, 0, sizeof dp);        
    int mx = -INF;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 2; j++){
            if (j==0){
                dp[i][j] = max(dp[i-1][1]+b[i], dp[i-1][2] + c[i]);
            }
            else if (j==1){
                dp[i][j] = max(dp[i-1][0]+a[i], dp[i-1][2] + c[i]);
            }
            else{
                dp[i][j] = max(dp[i-1][0]+a[i], dp[i-1][1] + b[i]);
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    exit(0);
}
