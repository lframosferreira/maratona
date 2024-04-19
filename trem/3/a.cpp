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

string st; ll x, y, n, m, q, l, r;

const int MAX = 5e3 + 10;
int dp[MAX][MAX];

int main(){ _
    cin >> n >> q;    
    cin >> st;
    st='#'+st;
    cin >> l >> r;
    cin >> x >> y;
    
    memset(dp, 0, sizeof dp);
    for (int j = 1; j <= n; j++){
        for (int i = j; i >= 1; i--){
            if (i==j) continue;
            if (i+1==j) dp[i][j] = st[i]!=st[j]; 
            else {
                dp[i][j]=(int)(st[i]!=st[j]) + dp[i+1][j-1];
            }
        }
    }

    ll ans=0;
    ans+=dp[l][r];;
    for (int j = 2; j <= q; j++){
        l = (l*y + (r*x)/n + 999999999) % n + 1;
        r = max(l, (r*x + y + 999999999) % n + 1);
        ans+=dp[l][r];
    }
    cout << ans << endl;
    exit(0);
}
