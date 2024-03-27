#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main() { _
 
 
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> v(n);
        for (ll &i: v) cin >> i;
        sort(v.begin(), v.end());
 
        ll ans = max(v[0]*v[1], v[n-2]*v[n-1]);
        cout << ans << endl;
    }
 
	exit(0);
}
