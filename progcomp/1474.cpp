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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e6;
const ll MAX = 1e9+10; // nao é, arrumar dps

ll fat[MAX];

ll fexp(ll a, ll b){
    a %=MOD;
    ll res=1;
    while (b>0){
        if (b&1) res *= a%MOD;
        a*=a%MOD;
        b>>=1;
    }
    return res;
}

int main(){ _
    ll N, K, L;
    fat[0]=fat[1]=1;
    for (int i = 2; i < MAX; i++) fat[i]=fat[i-1]*i%MOD;
    while (cin >> N >> K >> L){
        ll n10=0;
        ll n5;
        ll ans=0;
        while (n10*10 <= N){
            ll val10 = fexp(L, n10);  
            n5 = (N-n10*10)/5;
            ll val5=fexp(K, n5);
            ll nperm = fat[n10+n5]/(fat[n10]*fat[n5]);
            ans+=(nperm*val5%MOD*val10%MOD);
            n10++;
        }
        cout << setfill('0') << setw(6) << ans%MOD << endl;
    }
    exit(0);
}
