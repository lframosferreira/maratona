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

const ll MOD=1e9+7;

ll L, R;

ll dp[10];

ll fexp(ll a, ll b){
    a%=MOD;
    ll ans=1;
    while (b){
        if (b & 1) ans=ans*a%MOD; 
        a=a*a%MOD;
        b >>=1;
    }
    return ans;
}

ll calc(ll n){
    //if (dp[n] != -1) return dp[n];
    if (n <=9) return dp[n];
    ll a=n;
    ll cnt=0LL;
    while (a>=10){
        a/=10;
        cnt++;
    }
    ll b=n%(fexp(10, cnt));
    ll val;
    if (a&1) val = a * ((a-1)/2) % MOD;
    else val = (a/2)*(a-1) % MOD;
    return (45*a%MOD*cnt%MOD*fexp(10, cnt-1)%MOD + val * fexp(10, cnt)%MOD + a*(b+1)%MOD + calc(b))%MOD;
}

int main(){ 
    dp[0]=0LL;
    for (ll i = 1; i <= 9; i++) {
        dp[i]=i+dp[i-1];
    }
    while (cin >> L >> R){
        ll ans = calc(R)-calc(L-1);
        cout << (ans%MOD + MOD)%MOD << endl;
    } 
    exit(0);
}
