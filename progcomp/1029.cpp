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

const int MAX = 40;

int dp[MAX];
int fib[MAX];

int main(){ _
    int n; cin >> n;
    memset(dp, 0, sizeof dp);
    memset(fib, 0, sizeof fib);
    fib[1]=1;
    for (int i = 2; i < MAX;i++){
        fib[i] = fib[i-1]+fib[i-2];
        dp[i] = dp[i-1]+dp[i-2]+2;
    }
    while (n--){
        int x; cin >> x;
        cout << "fib(" << x << ") = " << dp[x] << " calls = " << fib[x] << endl; 
    }
    exit(0);
}
