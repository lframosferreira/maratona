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

bool ss(ll x, ll y) {
    int a = x < 0;
    int b = y < 0;
    return a == b;
}

int main(){ 
    int t; cin >> t;
    while (t--){
        int a; cin >> a;
        vector<ll> v(a);
        for (auto &i: v) cin >> i;
        ll ans = v[0];
        ll prev = v[0];
        for (int i = 1; i < a; i++){
            if (ss(prev, v[i])) {
                if (v[i] > prev){
                    ans -= prev;
                    ans += v[i];
                    prev = v[i];
                }
            } else {
               ans += v[i];
               prev = v[i];
           }
        }
        cout << ans << endl;
    }    
    exit(0);
}
