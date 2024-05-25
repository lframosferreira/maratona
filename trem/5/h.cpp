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

const int MAX = 2010;
string v[MAX];
string dp[MAX][MAX];

int main(){ 
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> v[i];
    } 
    // de cima é 1 da esquerda é 0, inicial é -1
    dp[0][0]=v[0][0];
    for (int i = 1; i < m; i++){
        dp[0][i]=dp[0][i-1]+v[0][i];
    }
    for (int i = 1; i < n; i++) dp[i][0]=dp[i-1][0]+v[i][0];
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (dp[i-1][j] < dp[i][j-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i][j-1]; 
            dp[i][j]+=v[i][j];
        }
    }
    cout << dp[n-1][m-1] << endl;
    exit(0);
}