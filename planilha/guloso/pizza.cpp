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
    ll sv = 0ll;
    for (int i = 0; i < n; i++) {
	    cin >> v[i];
	    sv+=v[i];
    }
    ll mx = 0ll;
    ll mxi = 0ll;
    ll mxinv = 0ll;
    ll mxinvi = 0ll;
    for (int i: v){
	    mx=max(mx, mxi=max(0ll, mxi+i));
    }
    for (int i: v){
	    mxinv=max(mxinv, mxinvi=max(0ll, mxinvi-i));
    }
    cout << max(mx, mxinv + sv) << endl;
    exit(0);
}
