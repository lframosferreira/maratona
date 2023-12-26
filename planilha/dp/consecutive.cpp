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

int main(){ _
    int n; cin >> n;
    vector<int> v(n);
    vector<pii> dp(n);
    for (int &i : v) cin >> i;
    dp[0] = {1, 0};
    for (int i = 1; i< n; i++){
       auto [s, idx] = dp[i-1];
       if (v[idx] + 1 == v[i]) dp[i] = { s+1, i};
       else dp[i] = {s, idx};
    }
    int pos = 0; ll mxn = dp[0].f;
    for (int i = 1; i < n; i++){
        if (dp[i].f > mxn){
            mxn = dp[i].f;
            pos = i;
        }
    }
    cout << mxn << endl;
    exit(0);

}
