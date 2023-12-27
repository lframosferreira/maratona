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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; ll h;
    cin >> n >> h;
    vector<pll> v(n);
    for (int i = 0; i < n; i++){
       ll x1, x2; cin >> x1 >> x2;
       v[i]={x1, x2};
    }
    int l = 0;
    int r = -1;
    ll ans = -LINF;
    ll currx = 0;
    ll currh = h;
    ll lastpos = v[0].f;//mudar
    while (true){
        if (currh > 0){
            r++;
            if (r==n) break;
            auto [a, b] = v[r];
            currx+=b-lastpos;
            currh-=a-lastpos;
            lastpos=b;
            if (currh > 0) ans=max(ans, currx+currh);
        } else {
            auto [a, b] = v[l];
            currx-=v[l+1].f-a;
            currh+=v[l+1].f-b;
            if (currh > 0) ans=max(ans, currx+currh);
            l++;
        } 
    } 
    cout << ans << endl;
    exit(0);
}
