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

const int MAX = 10e8+5;
const ll MOD=1e9+7;

ll L, R;

ll dp[MAX];

int main(){ _
    dp[0]=0;
    for (int i = 1; i < MAX-5;i++)dp[i]=(dp[i-1]+i%10+dp[i/10])%MOD;
    while (cin >> L >> R){
        cout << dp[R]-dp[L] << endl; 
    } 
    exit(0);
}
