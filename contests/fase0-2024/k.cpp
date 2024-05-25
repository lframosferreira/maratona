// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sz(v) (int)v.size()
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;
const int MAX = 2e2+10; // CORRIGIR

int T, K;
vi primes;
int dp[MAX][MAX];
vi is_prime;

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= T; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= T; j += i)
                is_prime[j] = false;
        }
    }
}

ll fexp(ll a, ll b){
    if (b==0) return 1;
    if (b%2==0) return fexp(a*a%MOD, b/2);
    return a * fexp(a, b-1)%MOD;
}

ll inv(ll x) {
    return fexp(x, MOD-2);
}

void print_dp(){
    for (int i = 1; i < sz(primes); i++){
        for (int j = 1; j <= K; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){ 
    cin >> T >> K; 
    memset(dp,0,sizeof dp);
    primes.pb(1);
    is_prime.resize(T+1, 1);
    sieve();
    dp[1][1]=inv(primes[1]);
    for (int i = 2; i < sz(primes); i++){
        dp[i][1]=inv(primes[i]);
        for (int j = 1; j < i; j++){
            dp[i][1] *= (primes[j]-1)%MOD*inv(primes[j])%MOD; 
        }
    }
    for (int i = 1; i < sz(primes); i++){
        for (int j = 2; j <= K; j++){
            if (i < j) continue;
            for (int idx=i-1; idx>=0; idx--){
                dp[i][j] += inv(primes[idx])*dp[idx][j-1]%MOD;
            } 
            dp[i][j]*=inv(i);
        }
    }
    print_dp();
    exit(0);
}
