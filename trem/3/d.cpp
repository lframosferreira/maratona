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

ll n, a, b;
vector<ll> v;
vector<ll> v2;

int can(ll x){
    v2.clear();v2.assign(v.begin(), v.end());
   for (ll &i: v2)i=max(0LL, i-b*x); 
   int cnt=0;
   for (int i = 0; i < v2.size();i++){
       cnt += v2[i]/(a-b) + (v2[i]%(a-b) != 0);
       if (cnt > x) return 0;
   }
   return 1;
}

int main(){ _
    cin >> n >> a >> b;
    v.clear();v.resize(n);
    for (ll &i:v)cin >> i;
    ll l=0,r=1e9+10;
    ll m;
    while (l < r){
        m = (l+r)/2;
        if (can(m)){
            r=m;
        } else{
            l=m+1;
        }
    } 
    cout << l << endl; 
    exit(0);
}
