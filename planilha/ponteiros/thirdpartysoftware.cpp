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
    int n, m; cin >> n >> m;
    
    vector<pair<pll, int>> v(n);
    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[i] = {{a, b}, i}; 
    }

    sort(v.begin(), v.end());
    
    if (n==1){
        if (v[0].f.f == 1 and v[0].f.s == m){
            cout << "YES" << endl;
            cout << 1 << endl;
            cout << 1 << endl;
            exit(0);
        } else {
            cout << "NO" << endl;
            exit(0);
        }
    }

    int l = 0;
    int r = 0;
    if (v[l].f.f != 1){
        cout << "NO" << endl;
        exit(0);
    }
    ll mx = -LINF;
    ll mx2 = -LINF;
    ll ans = 1;
    vector<int> libs;
    while (v[r+1].f.f == v[r].f.f){
        r++;
        if (r+1==n) break;
        continue;
    } 
    libs.pb(v[r].s);
    mx=max(mx, v[r].f.s);
    int currlib = v[r].s;
    while (r < n and mx < m){
        
        if (v[r].f.f > mx+1){
            cout << "NO" << endl;
            exit(0);
        }

        while (v[r].f.f <= mx+1){
            if (v[r].f.s > mx2){
                mx2=v[r].f.s;
                currlib=v[r].s;
            }
            r++;
            if (r==n) break;
        }
        libs.pb(currlib);
        ans++;
        mx=mx2;
    }
    if (mx < m) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << ans << endl;
        for (auto i: libs) cout << i+1 << " ";
        cout << endl;
    }

    exit(0);
}
