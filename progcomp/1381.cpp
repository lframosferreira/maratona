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
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
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

const ll MOD = 1300031;
const ll MAX= 1e6+10;

ll fat[MAX];
ll inv[MAX];

ll fexp(ll a, ll b){
    a %= MOD;
    ll res = 1;
    while (b){
        if (b & 1) res = res*a%MOD;
        a=a*a%MOD;
        b >>=1;
    }
    return res;
}

void build(){
    fat[0]=1;fat[2]=1;
    for (int i = 2; i < MAX; i++) fat[i]=fat[i-1]*i%MOD;
    inv[1]=1;
    for (int i = 2; i < MAX; i++) inv[i]=fexp(i, MOD-2);
}

int main(){ _
    build();
    int T; cin >> T;
    while (T--){
        ll N, C; cin >> N >> C;
        ll ans=0;

    }
    exit(0);
}
