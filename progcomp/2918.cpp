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

const int MAX = 10e6+5;
const ll MOD=1e9+7;

ll L, R;

ll dp[MAX];

ll sum_dig(ll x){
    ll ret = 0;
    while (x){
        ret+=x%10;
        x/=10;
    }
    return ret;
}

int main(){ _
    dp[0]=0;
    for (int i = 1; i < MAX-5;i++)dp[i]=(dp[i-1]+sum_dig(i))%MOD;
    for (int i = 0; i < 50; i++) cout << i << ": " << dp[i] << endl;
    while (cin >> L >> R){
        cout << dp[R]-dp[L-1] << endl; 
    } 
    exit(0);
}
