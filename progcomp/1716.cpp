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
typedef tuple<int, int , int> iii;
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


ll fexp(ll a, ll b, ll mod){
    a %= mod;
    ll res = 1;
    while (b){
        if (b & 1) res = res*a%mod;
        a=a*a%mod;
        b >>=1;
    }
    return res;
}

tuple<ll, ll, ll> mdc(ll m, ll n){
    if (m%n==0){
        return make_tuple(n, 0, 1);
    }
    auto [d, xl, yl] = mdc(n, m%n);
    return make_tuple(d, yl, xl-yl*(m/n));
}


int main(){ _
    int N, E, C; cin >> N >> E >> C; 
    
    int P, Q;
    for (int i = 2; i*i <= N; i++){
        if (N % i == 0){
            P = i;
            Q = N/i;
            break;
        }
    }
    
    ll phi = (P-1)*(Q-1);
    auto [a, x, b] = mdc(E, phi); 
    cout << fexp(C, x, N) << endl;
    exit(0);
}
