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
typedef pair<int , int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    while (true){
        int n, k; cin >> n >> k;
        if (n == 0 and k == 0) break;
        vi v(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i];
        vector<vector<ll>> dp(n+1, vector<ll>(k+1));
        for (int i = 1; i <= n; i++) dp[i][1] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i - 1; j++){
                if (v[j] < v[i]){
                    for (int q = 2; q <= k; q++) {
                        dp[i][q] += dp[j][q-1];
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans+=dp[i][k];
        cout << ans << endl;
    }
    exit(0);
}
