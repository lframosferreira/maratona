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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
ll dp[MAX];

int main(){ _
    int n; cin >> n;
    dp[0] = 1;
    for (int i = 1; i < 16; i++) dp[i] = dp[i-1] * 26 % MOD;
    for (int i = 16; i < MAX; i++) dp[i] = (26*dp[i-1] - dp[i-16])%MOD;
    for (int i = 0; i < 101; i++){
        dbg(i);
        dbg(dp[i]);
    }
    // cout << dp[n] << endl;
    exit(0);
}
