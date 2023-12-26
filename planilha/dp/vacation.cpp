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

#define sea 0
#define bugs 1
#define homework 2

int main(){ _
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i = 0; i < n; i++){
        cin >> v[i][sea] >> v[i][bugs] >> v[i][homework];
    }
    vector<vector<ll>> dp(n, vector<ll>(3));
    dp[0][sea] = v[0][sea];
    dp[0][bugs] = v[0][bugs];
    dp[0][homework] = v[0][homework];
    for (int i = 1; i< n; i++){
        dp[i][sea] += max(dp[i-1][bugs], dp[i-1][homework]) + v[i][sea];
        dp[i][bugs] += max(dp[i-1][sea], dp[i-1][homework]) + v[i][bugs];
        dp[i][homework] += max(dp[i-1][sea], dp[i-1][bugs]) + v[i][homework];
    }
    cout << max({dp[n-1][sea], dp[n-1][bugs], dp[n-1][homework]}) << endl;
    exit(0);
}
