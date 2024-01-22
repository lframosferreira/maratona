#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb pushback

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int , int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ 
    int t; cin >> t;
    while (t--){
        int n, q; cin >> n >> q;
        vector<ll> v(n+1);
        for (int i = 1; i<=n; i++) cin >> v[i];
        while (q--){
            int s, d, k; cin >> s >> d >> k;
            ll ans = 0;
            for (int i = 1; i <= k; i++){
                ans += i * v[s + d*(i-1)];
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    exit(0);
}

// tle
