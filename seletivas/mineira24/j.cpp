// pescoço pra baixo é canela

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define bs bitset
#define umap unordered_map
#define uset unordered_set
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

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

int main(){ _
    int n, k; cin >> n >> k;
    vi a(n+1);
    vector<pii> v(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];    
        v[i]={max(1, i-k), min(n, i+k)};
    }
    vi dp(n+1); 
    for (int i = 1; i <= n; i++){
        if (a[i]==0){
            dp[i]=v[i].s-v[i].f+1;
            continue;
        }
        if (v[i].f > v[a[i]].s){
            dp[i]=dp[a[i]]+(v[i].s-v[i].f+1);
        }else {
            dp[i] = dp[a[i]] + (v[i].s-v[a[i]].s); 
        }
    }
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << endl;
    exit(0);
}
